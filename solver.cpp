/*
 * solver.cpp
 *
 *  Created on: 12.11.2013
 *      Author: David
 */

#include "solver.h"
#include <iostream>
#include "math.h"
using namespace std;

Solver::Solver(IO& SimIO) :
		SimIO(SimIO) {
}
RealType Solver::computeResidual(GridFunction& sourcegridfunction,
		GridFunction& rhs) {
	PointType delta;
	delta[0] = SimIO.para.deltaX;
	delta[1] = SimIO.para.deltaY;

	MultiIndexType begin, end;
	begin[0] = 1;
	end[0] = sourcegridfunction.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = sourcegridfunction.griddimension[1] - 2;
	//while ((it < SimIO.para.iterMax) && (res > SimIO.para.eps)) {
	GridFunction branch_1(sourcegridfunction.griddimension);
	//branch_1.Grid_Print();
	Pxx(branch_1, sourcegridfunction, delta);
	//branch_1.Grid_Print();
	GridFunction branch_2(sourcegridfunction.griddimension);
	//branch_2.Grid_Print();
	Pyy(branch_2, sourcegridfunction, delta);
	//branch_2.Grid_Print();

	branch_1.AddToGridFunction(begin, end, 1.0, branch_2);
	//branch_1.Grid_Print();
	branch_1.AddToGridFunction(begin, end, -1.0, rhs);
	//branch_1.Grid_Print();
	branch_1.MultiplyGridFunctions(begin, end, branch_1);
	//branch_1.Grid_Print();
	branch_1.ScaleGridFunction(begin, end,
			1.0 / (SimIO.para.iMax * SimIO.para.jMax));

	RealType res = 0.0;
	for (int i = 0; i < SimIO.para.iMax; i++) {
		for (int j = 0; j < SimIO.para.jMax; j++) {

			res += branch_1.getGridFunction()[i][j];
		}
	}
	return sqrt(res);

}
void Solver::SORCycle(GridFunction* gridfunction, GridFunctionType& rhs,
		const PointType& delta, RealType omega) {

}
