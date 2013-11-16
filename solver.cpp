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
	IndexType it = 0;
	RealType res = SimIO.para.eps + 1.0;
	PointType delta;
	delta[0]=SimIO.para.deltaX;
	delta[1]=SimIO.para.deltaY;

	MultiIndexType begin, end;
	begin[0] = 1;
	end[0] = sourcegridfunction.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = sourcegridfunction.griddimension[1] - 2;
	while ((it < SimIO.para.iterMax) && (res > SimIO.para.eps)) {

		res = 0.0;
		for (int i = 0; i < SimIO.para.iMax; i++) {
			for (int j = 0; j < SimIO.para.jMax; j++) {
				GridFunction branch_1(sourcegridfunction.griddimension);
				Pxx(branch_1,sourcegridfunction,delta);
				GridFunction branch_2(sourcegridfunction.griddimension);
				Pyy(branch_2,sourcegridfunction,delta);

				branch_1.AddToGridFunction(begin,end,1.0,branch_2);
				branch_1.AddToGridFunction(begin,end,-1.0,rhs);

				branch_1.MultiplyGridFunctions(begin,end,branch_1);
				branch_1.ScaleGridFunction(begin,end,1/(SimIO.para.iMax*SimIO.para.jMax));

				res += branch_1.getGridFunction()[i][j];
				res = sqrt(res);
				cout << res;
		}
	}
//	res = sqrt(res);
//	cout << res;
	it++;
}
return 0.0;

}
void Solver::SORCycle(GridFunction* gridfunction, GridFunctionType& rhs,
	const PointType& delta, RealType omega) {

}
