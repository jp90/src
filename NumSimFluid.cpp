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

using namespace std;

int main() {
	char input[] = "./src/inputvals.txt";
	char output[] = "./src/inputvals.txt";
	IO SimIO(input, output);

	IndexType n=0;
	RealType t=0;

	//initialize u,v,p
	MultiIndexType begin,end,offset;
	PointType h;
	h[0]=1.0;
	h[1]=1.0;
	begin[0] = 0;
	end[0] = SimIO.para.iMax-1;
	begin[1] = 0;
	end[1] = SimIO.para.jMax-1;
	GridFunction u(SimIO.para.iMax, SimIO.para.jMax);

	u.SetGridFunction(begin,end,SimIO.para.ui);
	begin[0] = 2;
	end[0] = SimIO.para.iMax-3;
	begin[1] = 2;
	end[1] = SimIO.para.jMax-3;
	u.SetGridFunction(begin,end,2.0);

	GridFunction v(SimIO.para.iMax, SimIO.para.jMax);
	v.SetGridFunction(begin,end,SimIO.para.vi);
	//v.Grid_Print();


	GridFunction p(SimIO.para.iMax, SimIO.para.jMax);
	p.SetGridFunction(begin,end,SimIO.para.pi);
	//p.Grid_Print();

	//comp.computeMomentumEquations(v, v, u,v, v.getGridFunction(), v.getGridFunction(),h, SimIO.para.deltaT);

	//RealType alpha = 1.0;
	//RealType re = 0.5;
//	MultiIndexType begin,end,
	MultiIndexType dim;
	dim = u.griddimension;
//	begin[0]=0;
	//end[0]=u.griddimension[0];
	//begin[1]=0;
	//end[1]=u.griddimension[1];
GridFunction gx(u.griddimension);
GridFunction gy(u.griddimension);

GridFunction g(u.griddimension);
GridFunction f(u.griddimension);

Computation computer(SimIO);

u.Grid_Print();
computer.setBoundaryG(u);
u.Grid_Print();


//computer.computeMomentumEquations(f,g,u,v,gx,gy,h,SimIO.para.deltaT);
//f.Grid_Print();
//g.Grid_Print();
	while (t<SimIO.para.tEnd){

		n++;
		t+=SimIO.para.deltaT;
	}
	cout<<"laeuft!";
/*	MultiIndexType begin, end, offset, gridreadbegin, gridreadend,
			gridwritebegin, gridwriteend;

	PointType h;
	h[0] = 1.0;
	h[1] = 1.0;
	MultiIndexType dim;
	dim[0] = 20;
	dim[1] = 20;
	GridFunction u(dim);
	begin[0] = 0;
	end[0] = 19;
	begin[1] = 0;
	end[1] = 19;

	u.SetGridFunction(begin, end, 4.0);

	begin[0] = 5;
	end[0] = 12;
	begin[1] = 3;
	end[1] = 15;

	u.SetGridFunction(begin, end, 2.0);

	begin[0] = 1;
	end[0] = 18;
	begin[1] = 1;
	end[1] = 18;
	RealType alpha = 1.0;
	GridFunction FFX = Uy(dim, u, alpha, h);

	u.Grid_Print();
	cout << endl;
	FFX.Grid_Print();*/
}
