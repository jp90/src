/*
 * computation.cpp
 *
 *  Created on: 12.11.2013
 *      Author: David
 */

#include "computation.h"
#include <iostream>

using namespace std;

Computation::Computation(IO& SimIO) :
		SimIO(SimIO) {
}

RealType Computation::computeTimesstep(RealType uMax, RealType vMax) {
	RealType deltaT, min, c;
	c = SimIO.para.re
			/ (2.0
					* (1.0 / (SimIO.para.deltaX * SimIO.para.deltaX)
							+ 1.0 / (SimIO.para.deltaY * SimIO.para.deltaY)));
	if ((c < SimIO.para.deltaX / uMax) && (c < SimIO.para.deltaY / vMax))
		min = c;

	else if ((SimIO.para.deltaX / uMax < c)
			&& (SimIO.para.deltaX / uMax < SimIO.para.deltaY / vMax))
		min = SimIO.para.deltaX / uMax;

	else
		min = SimIO.para.deltaY / vMax;

	deltaT = SimIO.para.tau * min;
	return deltaT;
}

void Computation::computeNewVelocities(GridFunction& u, GridFunction& v,
		GridFunction& f, GridFunction& g, GridFunction& p, RealType deltaT) {
	GridFunction branch_1(p.griddimension);
	MultiIndexType begin, end;
	begin[0] = 0;
	end[0] = u.griddimension[0] - 1;
	begin[1] = 0;
	end[1] = u.griddimension[1] - 1;
	// u Update
	PointType delta;
	delta[0] = SimIO.para.deltaX;
	delta[1] = SimIO.para.deltaY;
	Px(branch_1, p, delta);
	f.AddToGridFunction(begin, end, -SimIO.para.deltaT, branch_1);
	u.SetGridFunction(begin, end, 1.0, f);
	// v Update
	GridFunction branch_2(p.griddimension);
	Py(branch_2, p, delta);
	g.AddToGridFunction(begin, end, -SimIO.para.deltaT, branch_2);
	v.SetGridFunction(begin, end, 1.0, g);

}
;

void Computation::computeMomentumEquations(GridFunction& f, GridFunction& g,
		GridFunction& u, GridFunction& v, GridFunction& gx, GridFunction& gy,
		RealType& deltaT) {
	PointType h;
	h[0] = SimIO.para.deltaX;
	h[1] = SimIO.para.deltaY;
	RealType alpha = SimIO.para.alpha;
	RealType re = 0.5;
	MultiIndexType begin, end;
	begin[0] = 0;
	end[0] = u.griddimension[0] - 1;
	begin[1] = 0;
	end[1] = u.griddimension[1] - 1;

	// Term F

	Uxx(f, u, h);

	GridFunction branch_2(u.griddimension);
	Uyy(branch_2, u, h);
	f.AddToGridFunction(begin, end, 1.0, branch_2);
	f.ScaleGridFunction(begin, end, 1.0 / re);
	GridFunction branch_3(u.griddimension);
	UUx(branch_3, u, alpha, h);
	GridFunction branch_4(u.griddimension);
	UVy(branch_4, u, v, alpha, h);
	branch_3.AddToGridFunction(begin, end, 1.0, branch_4);

	f.AddToGridFunction(begin, end, -1.0, branch_3);
	// KILL branch 2-4

	//MISSING g_x

	f.ScaleGridFunction(begin, end, deltaT);
	f.AddToGridFunction(begin, end, 1.0, u);

	//Term G

	Vxx(g, v, h);
	GridFunction branch_6(u.griddimension);
	Vyy(branch_6, v, h);
	g.AddToGridFunction(begin, end, 1.0, branch_6);
	g.ScaleGridFunction(begin, end, 1.0 / re);

	GridFunction branch_7(u.griddimension);
	UVx(branch_7, u, v, alpha, h);
	GridFunction branch_8(u.griddimension);
	VVy(branch_8, v, alpha, h);
	branch_7.AddToGridFunction(begin, end, 1.0, branch_8);

	g.AddToGridFunction(begin, end, -1.0, branch_7);

	//MISSING g_y term

	g.ScaleGridFunction(begin, end, deltaT);
	g.AddToGridFunction(begin, end, 1.0, v);

}

void Computation::setBoundaryU(GridFunction& u) {
	MultiIndexType begin, end;

	// u_0,j = 0
	begin[0] = 0;
	end[0] = 0;
	begin[1] = 0;
	end[1] = u.griddimension[1] - 1;
	u.SetGridFunction(begin, end, 0.0);

	// u_iMax,j = 0
	begin[0] = u.griddimension[0] - 1;
	end[0] = u.griddimension[0] - 1;
	begin[1] = 0;
	end[1] = u.griddimension[1] - 1;
	u.SetGridFunction(begin, end, 0.0);


	// u_i,0
	begin[0] = 0;
	end[0] = u.griddimension[0] - 1;
	begin[1] = 0;
	end[1] = 0;
	MultiIndexType Offset;
	Offset[0] = 0;
	Offset[1] = 1;
	u.SetGridFunction(begin, end, -1.0,Offset);

	// u_i,jMax
	begin[0] = 0;
	end[0] = u.griddimension[1] - 1;
	begin[1] = u.griddimension[1] - 1;
	end[1] = u.griddimension[1] - 1;
	Offset[0] = 0;
	Offset[1] = -1;
	u.SetGridFunction(begin, end, -1.0,u,Offset,2.0);


}
void Computation::setBoundaryV(GridFunction& v) {
	MultiIndexType begin, end;

	// v_0,j = -v_1,j
	begin[0] = 0;
	end[0] = 0;
	begin[1] = 0;
	end[1] = v.griddimension[1] - 1;
	MultiIndexType Offset;
	Offset[0] = 1;
	Offset[1] = 0;
	v.SetGridFunction(begin, end, -1.0,Offset);

	// v_iMax,j = -v_iMax-1,j
	begin[0] = v.griddimension[0] - 1;
	end[0] = v.griddimension[0] - 1;
	begin[1] = 0;
	end[1] = v.griddimension[1] - 1;
	Offset[0] = -1;
    Offset[1] = 0;
	v.SetGridFunction(begin, end, -1.0,Offset);



	// v_i,0 = 0
	begin[0] = 0;
	end[0] = v.griddimension[0] - 1;
	begin[1] = 0;
	end[1] = 0;
	v.SetGridFunction(begin, end, 0.0);

	// v_i,jMax =0
	begin[0] = 0;
	end[0] = v.griddimension[1] - 1;
	begin[1] = v.griddimension[1] - 1;
	end[1] = v.griddimension[1] - 1;
	v.SetGridFunction(begin, end, 0.0);


}
void Computation::setBoundaryP(GridFunction& p) {
	MultiIndexType begin, end;
	// p_0,j = p_1,j
	begin[0] = 0;
	end[0] = 0;
	begin[1] = 0;
	end[1] = p.griddimension[1] - 1;
	MultiIndexType Offset;
	Offset[0] = 1;
	Offset[1] = 0;
	p.SetGridFunction(begin, end, 1.0,Offset);

	// p_iMax+1,j = p_iMax,j
	begin[0] = p.griddimension[0] - 1;
	end[0] = p.griddimension[0] - 1;
	begin[1] = 0;
	end[1] = p.griddimension[1] - 1;
	Offset[0] = -1;
	Offset[1] = 0;
	p.SetGridFunction(begin, end, 1.0,Offset);


	// p_i,0 = p_i,1
	begin[0] = 0;
	end[0] = p.griddimension[0] - 1;
	begin[1] = 0;
	end[1] = 0;
	Offset[0] = 0;
	Offset[1] = 1;
	p.SetGridFunction(begin, end, 1.0,Offset);

	// p_i,jMax+1 = p_i,jMax
	begin[0] = 0;
	end[0] = p.griddimension[0] - 1;
	begin[1] = p.griddimension[1] - 1;
	end[1] = p.griddimension[1] - 1;
	Offset[0] = 0;
	Offset[1] = -1;
	p.SetGridFunction(begin, end, 1.0,Offset);

	}
void Computation::setBoundaryF(GridFunction& f,GridFunction& u) {
	MultiIndexType begin, end;
	begin[0] = 0;
	begin[1] = 0;
	end[0] = 0;
	end[1] = f.griddimension[0] - 1;
	f.SetGridFunction(begin, end, 1.0,u);

	begin[0] = f.griddimension[0] - 2;
	begin[1] = f.griddimension[0] - 2;
	end[0] = 0;
	end[1] = f.griddimension[0] - 1;
	f.SetGridFunction(begin, end, 1.0,u);
}
void Computation::setBoundaryG(GridFunction& g,GridFunction& v) {

	MultiIndexType begin, end;
	begin[0] = 0;
	begin[1] = g.griddimension[0]-1;
	end[0] = 0;
	end[1] = 0;
	g.SetGridFunction(begin, end, 1.0,v);

	begin[0] = 0;
	begin[1] = g.griddimension[0]-1;
	end[0] = g.griddimension[1]-2;
	end[1] = g.griddimension[1]-2;
	g.SetGridFunction(begin, end, 1.0,v);
}

void Computation::computeRighthandSide(GridFunction& rhs, GridFunction& f, GridFunction& g,
										RealType deltaT) {

	GridFunction branch_1(g.griddimension);

	MultiIndexType begin, end;
	begin[0] = 0;
	end[0] = f.griddimension[0] - 1;
	begin[1] = 0;
	end[1] = f.griddimension[1] - 1;
    PointType delta;
    delta[0]=SimIO.para.deltaX;
    delta[1]=SimIO.para.deltaY;
    Fx(rhs, f, delta);
	Gy(branch_1, g, delta);

	rhs.AddToGridFunction(begin, end, 1.0, branch_1);
	rhs.ScaleGridFunction(begin, end, 1.0/deltaT);

}

