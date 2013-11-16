//============================================================================
// Name        : NumSimFluid.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "IO.hpp"
#include "gridfunction.h"
#include "stencil.h"
#include "derivatives.h"
#include "computation.h"
#include "solver.h"

using namespace std;

int main() {
	char input[] = "./src/inputvals.txt";
	char output[] = "./src/inputvals.txt";
	IO SimIO(input, output);

	IndexType n = 0;
	RealType t = 0;

	//initialize u,v,p
	MultiIndexType begin, end;

	begin[0] = 0;
	end[0] = SimIO.para.iMax - 1;
	begin[1] = 0;
	end[1] = SimIO.para.jMax - 1;
	GridFunction u(SimIO.para.iMax, SimIO.para.jMax);
/*
	u.SetGridFunction(begin, end, SimIO.para.ui);
	begin[0] = 2;
	end[0] = SimIO.para.iMax - 3;
	begin[1] = 2;
	end[1] = SimIO.para.jMax - 3;
	u.SetGridFunction(begin, end, 2.0); */

	GridFunction v(SimIO.para.iMax, SimIO.para.jMax);
	v.SetGridFunction(begin, end, SimIO.para.vi);
	//v.Grid_Print();

	GridFunction p(SimIO.para.iMax, SimIO.para.jMax);
	p.SetGridFunction(begin, end, SimIO.para.pi);
	begin[0] = 2;
	end[0] = SimIO.para.iMax - 3;
	begin[1] = 2;
	end[1] = SimIO.para.jMax - 3;
	p.SetGridFunction(begin, end, 2.0);


	GridFunction gx(u.griddimension);
	GridFunction gy(u.griddimension);

	GridFunction g(u.griddimension);
	GridFunction f(u.griddimension);

	Computation computer(SimIO);
	Solver solve(SimIO);
//	u.Grid_Print();
//	computer.setBoundaryG(u);
//	u.Grid_Print();


	while (t < SimIO.para.tEnd) {
		// compute timestep size deltaT
		RealType uMax = u.MaxValueGridFunction(begin, end);
		RealType vMax = v.MaxValueGridFunction(begin, end);
		RealType deltaT = computer.computeTimesstep(uMax, vMax);
		// set boundary values?!

		// Compute F and G
		computer.computeMomentumEquations(f, g, u, v, gx, gy, deltaT);
		// set right hand side of p equation

		// als test rhs = 0 Matrix
		GridFunction rhs(p.griddimension);
		// compute residuum in solver

		solve.computeResidual(p,rhs);

		// Update velocites u and v
		computer.computeNewVelocities(u, v, f, g, p, deltaT);
		n++;
		t += deltaT;
	}
	cout << "laeuft!";

}
