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
	RealType t = 0.0;

	//initialize u,v,p
	MultiIndexType begin, end;
	//Initialize u-velocity
	begin[0] = 1;
	end[0] = SimIO.para.iMax - 1;
	begin[1] = 1;
	end[1] = SimIO.para.jMax;
	GridFunction u(SimIO.para.iMax+2, SimIO.para.jMax+2);
	u.SetGridFunction(begin, end, SimIO.para.ui);
	//Initialize v-velocity
	GridFunction v(SimIO.para.iMax+2, SimIO.para.jMax+2);
	begin[0] = 1;
	end[0] = SimIO.para.iMax;
	begin[1] = 1;
	end[1] = SimIO.para.jMax -1;
	v.SetGridFunction(begin, end, SimIO.para.vi);
	//Initialize pressure
	GridFunction p(SimIO.para.iMax+2, SimIO.para.jMax+2);
	begin[0] = 1;
	end[0] = SimIO.para.iMax;
	begin[1] = 1;
	end[1] = SimIO.para.jMax;
	p.SetGridFunction(begin, end, SimIO.para.pi);

	GridFunction gx(u.griddimension);
	GridFunction gy(v.griddimension);

	GridFunction f(u.griddimension);
	GridFunction g(v.griddimension);

	GridFunction rhs(p.griddimension);

	Computation computer(SimIO);
	Solver solve(SimIO);

	PointType delta;
    //computer.setBoundaryU(u);
    //u.Grid_Print();
	delta[0]=SimIO.para.deltaX;
	delta[1]=SimIO.para.deltaY;
	//Start Main Loop

	computer.setBoundaryU(u);
    computer.setBoundaryV(v);
    GridFunction ableitung(u.griddimension);
    Uyy(ableitung,u,delta);
    u.Grid_Print();
    ableitung.Grid_Print();




int count=0;
	while ((t < SimIO.para.tEnd)){

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

		computer.setBoundaryF(f,u);
		computer.setBoundaryG(g,v);

	/*	cout<<"u"<<endl;
		u.Grid_Print();

		cout<<"v"<<endl;
		v.Grid_Print();

		cout<<"f"<<endl;
		f.Grid_Print();

		cout<<"g"<<endl;
		g.Grid_Print(); */




		// set right hand side of p equation
		computer.computeRighthandSide(rhs,f,g,deltaT);
	//	rhs.Grid_Print();
		//SOR-SOLVER
		int it =0;
		RealType Residuum = SimIO.para.eps+1.0;
		while ((it < SimIO.para.iterMax) && (Residuum > SimIO.para.eps)) {
      //      cout << "Computing pressure" <<endl;
            //Set boundary
            computer.setBoundaryP(p);
            // SOR Cycle
            solve.SORCycle(p,rhs);

			Residuum = solve.computeResidual(p,rhs);
			cout << "Current Residuum: ";
			cout << Residuum<<endl;
			cout << "it= "<<it << "n="<<n<< endl;
			it++;
		}
		if (Residuum>10.0)
			return 0;

		// Update velocites u and v
		computer.computeNewVelocities(u, v, f, g, p, deltaT);
		n++;
		cout << "t= " << t<< endl;
		t += deltaT;
		count++;
	}
	cout << "laeuft!";
}
