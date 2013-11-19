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
	//Initialize u-velocity
	begin[0] = 0;
	end[0] = SimIO.para.iMax - 1;
	begin[1] = 0;
	end[1] = SimIO.para.jMax - 1;
	GridFunction u(SimIO.para.iMax, SimIO.para.jMax);
	u.SetGridFunction(begin, end, SimIO.para.ui);
	//Initialize v-velocity
	GridFunction v(SimIO.para.iMax, SimIO.para.jMax);
	v.SetGridFunction(begin, end, SimIO.para.vi);

	//Initialize pressure
	GridFunction p(SimIO.para.iMax, SimIO.para.jMax);
	p.SetGridFunction(begin, end, SimIO.para.pi);


	GridFunction gx(u.griddimension);
	GridFunction gy(u.griddimension);

	GridFunction g(u.griddimension);
	GridFunction f(u.griddimension);

	GridFunction rhs(p.griddimension);

	Computation computer(SimIO);
	Solver solve(SimIO);

	PointType delta;

	delta[0]=SimIO.para.deltaX;
	delta[1]=SimIO.para.deltaY;
	//Start Main Loop
	while (t < SimIO.para.tEnd) {

		SimIO.writeVTKFile(u.griddimension,u.getGridFunction(),v.getGridFunction(),p.getGridFunction(),delta,n);

		// compute timestep size deltaT
		RealType uMax = u.MaxValueGridFunction(begin, end);
		RealType vMax = v.MaxValueGridFunction(begin, end);
		RealType deltaT = computer.computeTimesstep(uMax, vMax);
		// set boundary values
		computer.setBoundaryU(u);
		computer.setBoundaryV(v);
		// Compute F and G
		computer.computeMomentumEquations(f, g, u, v, gx, gy, deltaT);

		// set right hand side of p equation
		computer.computeRighthandSide(rhs,f,g,deltaT);

		//SOR-SOLVER
		int it =0;
		RealType Residuum = SimIO.para.eps+1.0;
		while ((it < SimIO.para.iterMax) && (Residuum > SimIO.para.eps)) {
            cout << "Computing pressure" <<endl;
            //Set boundary
            computer.setBoundaryP(p);
            // SOR Cycle
            solve.SORCycle(p,rhs);

			Residuum = solve.computeResidual(p,rhs);
			cout << "Current Residum: ";
			cout << Residuum<<endl;
			it++;
		}

		// Update velocites u and v
		computer.computeNewVelocities(u, v, f, g, p, deltaT);
		n++;
		t += deltaT;
	}
	cout << "laeuft!";

}
