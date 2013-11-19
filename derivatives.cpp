/* * derivatives.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: jan-philippwolf
 */
#include "derivatives.h"

void Ux(GridFunction& output, GridFunction& u, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = u.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = u.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setUxStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, u, output);

}

void Uy(GridFunction& output, GridFunction& u, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = u.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = u.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setUyStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, u, output);

}

void Uxx(GridFunction& output, GridFunction& u, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = u.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = u.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setUxxStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, u, output);

}

void Uyy(GridFunction& output, GridFunction& u, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = u.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = u.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setUyyStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, u, output);

}

void Px(GridFunction& output, GridFunction& p, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = p.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = p.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setPxStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, p, output);

}

void Py(GridFunction& output, GridFunction& p, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = p.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = p.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setPyStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, p, output);

}
void Pxx(GridFunction& output, GridFunction& p, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = p.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = p.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setPxxStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, p, output);

}
void Pyy(GridFunction& output, GridFunction& p, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = p.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = p.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setPyyStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, p, output);

}
void Vxx(GridFunction& output, GridFunction& v, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = v.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = v.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setUxxStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, v, output);

}

void Vyy(GridFunction& output, GridFunction& v, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = v.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = v.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setUyyStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, v, output);

}

void UUx(GridFunction& output, GridFunction& u, const RealType alpha,
		const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = u.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = u.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setUUx_1Stencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, u, output);
	output.MultiplyGridFunctions(begin, end, output);

	GridFunction branch_2(u.griddimension);
	Stencil stencil_2(3, h);
	stencil_2.setUUx_2Stencil();
	stencil_2.ApplyStencilOperator(begin, end, begin, end, u, branch_2);
	branch_2.MultiplyGridFunctions(begin, end, branch_2);

	output.AddToGridFunction(begin, end, -1.0, branch_2);
	output.ScaleGridFunction(begin, end, 1.0 / h[0]);

	GridFunction branch_3(u.griddimension);
	Stencil stencil_3(3, h);
	stencil_3.setUUx_3Stencil();
	stencil_3.ApplyStencilOperator(begin, end, begin, end, u, branch_3);
	branch_3.MultiplyGridFunctions(begin, end, branch_3);

	GridFunction branch_4(u.griddimension);
	Stencil stencil_4(3, h);
	stencil_4.setUUx_4Stencil();
	stencil_4.ApplyStencilOperator(begin, end, begin, end, u, branch_4);
	branch_4.MultiplyGridFunctions(begin, end, branch_4);

	branch_3.MultiplyGridFunctions(begin, end, branch_4);

	GridFunction branch_5(u.griddimension);
	Stencil stencil_5(3, h);
	stencil_5.setUUx_5Stencil();
	stencil_5.ApplyStencilOperator(begin, end, begin, end, u, branch_5);
	branch_5.MultiplyGridFunctions(begin, end, branch_5);

	GridFunction branch_6(u.griddimension);
	Stencil stencil_6(3, h);
	stencil_6.setUUx_6Stencil();
	stencil_6.ApplyStencilOperator(begin, end, begin, end, u, branch_6);
	branch_6.MultiplyGridFunctions(begin, end, branch_6);

	branch_5.MultiplyGridFunctions(begin, end, branch_6);

	branch_3.AddToGridFunction(begin, end, -1.0, branch_5);

	branch_3.ScaleGridFunction(begin, end, alpha / h[0]);

	output.AddToGridFunction(begin, end, 1.0, branch_3);

}

void VVy(GridFunction& output, GridFunction& v, const RealType alpha,
		const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = v.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = v.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setVVy_1Stencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, v, output);
	output.MultiplyGridFunctions(begin, end, output);

	GridFunction branch_2(v.griddimension);
	Stencil stencil_2(3, h);
	stencil_2.setVVy_2Stencil();
	stencil_2.ApplyStencilOperator(begin, end, begin, end, v, branch_2);
	branch_2.MultiplyGridFunctions(begin, end, branch_2);

	output.AddToGridFunction(begin, end, -1.0, branch_2);
	output.ScaleGridFunction(begin, end, 1.0 / h[1]);

	GridFunction branch_3(v.griddimension);
	Stencil stencil_3(3, h);
	stencil_3.setVVy_3Stencil();
	stencil_3.ApplyStencilOperator(begin, end, begin, end, v, branch_3);
	branch_3.MultiplyGridFunctions(begin, end, branch_3);

	GridFunction branch_4(v.griddimension);
	Stencil stencil_4(3, h);
	stencil_4.setVVy_4Stencil();
	stencil_4.ApplyStencilOperator(begin, end, begin, end, v, branch_4);
	branch_4.MultiplyGridFunctions(begin, end, branch_4);

	branch_3.MultiplyGridFunctions(begin, end, branch_4);

	GridFunction branch_5(v.griddimension);
	Stencil stencil_5(3, h);
	stencil_5.setVVy_5Stencil();
	stencil_5.ApplyStencilOperator(begin, end, begin, end, v, branch_5);
	branch_5.MultiplyGridFunctions(begin, end, branch_5);

	GridFunction branch_6(v.griddimension);
	Stencil stencil_6(3, h);
	stencil_6.setVVy_6Stencil();
	stencil_6.ApplyStencilOperator(begin, end, begin, end, v, branch_6);
	branch_6.MultiplyGridFunctions(begin, end, branch_6);

	branch_5.MultiplyGridFunctions(begin, end, branch_6);

	branch_3.AddToGridFunction(begin, end, -1.0, branch_5);

	branch_3.ScaleGridFunction(begin, end, alpha / h[1]);

	output.AddToGridFunction(begin, end, 1.0, branch_3);

}

void UVx(GridFunction& output, GridFunction& u, GridFunction& v,
		const RealType alpha, const PointType& h) {
	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = u.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = u.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setUVx_1Stencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, u, output);

	GridFunction branch_2(u.griddimension);
	Stencil stencil_2(3, h);
	stencil_2.setUVx_2Stencil();
	stencil_2.ApplyStencilOperator(begin, end, begin, end, v, branch_2);
	output.MultiplyGridFunctions(begin, end, branch_2);

	GridFunction branch_3(u.griddimension);
	Stencil stencil_3(3, h);
	stencil_3.setUVx_3Stencil();
	stencil_3.ApplyStencilOperator(begin, end, begin, end, u, branch_3);

	GridFunction branch_4(u.griddimension);
	Stencil stencil_4(3, h);
	stencil_4.setUVx_4Stencil();
	stencil_4.ApplyStencilOperator(begin, end, begin, end, v, branch_4);
	branch_3.MultiplyGridFunctions(begin, end, branch_4);
	output.AddToGridFunction(begin, end, -1.0, branch_3);
	output.ScaleGridFunction(begin, end, 1.0 / h[0]);
//bis hier 1. Zeile
	GridFunction branch_5(u.griddimension);
	Stencil stencil_5(3, h);
	stencil_5.setUVx_5Stencil();
	stencil_5.ApplyStencilOperator(begin, end, begin, end, u, branch_5);

	GridFunction branch_6(u.griddimension);
	Stencil stencil_6(3, h);
	stencil_6.setUVx_6Stencil();
	stencil_6.ApplyStencilOperator(begin, end, begin, end, v, branch_6);
	branch_5.MultiplyGridFunctions(begin, end, branch_6);

	GridFunction branch_7(u.griddimension);
	Stencil stencil_7(3, h);
	stencil_7.setUVx_7Stencil();
	stencil_7.ApplyStencilOperator(begin, end, begin, end, u, branch_7);

	GridFunction branch_8(u.griddimension);
	Stencil stencil_8(3, h);
	stencil_8.setUVx_8Stencil();
	stencil_8.ApplyStencilOperator(begin, end, begin, end, v, branch_8);
	branch_7.MultiplyGridFunctions(begin, end, branch_8);
	branch_5.AddToGridFunction(begin, end, -1.0, branch_7);
	branch_5.ScaleGridFunction(begin, end, alpha * 1.0 / h[0]);
//bis hier 2. Zeile
	output.AddToGridFunction(begin, end, 1.0, branch_5);
}

void UVy(GridFunction& output, GridFunction& u, GridFunction& v,
		const RealType alpha, const PointType& h) {
	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = u.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = u.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setUVy_1Stencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, v, output);
	GridFunction branch_2(u.griddimension);
	Stencil stencil_2(3, h);
	stencil_2.setUVy_2Stencil();
	stencil_2.ApplyStencilOperator(begin, end, begin, end, u, branch_2);
	output.MultiplyGridFunctions(begin, end, branch_2);

	GridFunction branch_3(u.griddimension);
	Stencil stencil_3(3, h);
	stencil_3.setUVy_3Stencil();
	stencil_3.ApplyStencilOperator(begin, end, begin, end, v, branch_3);

	GridFunction branch_4(u.griddimension);
	Stencil stencil_4(3, h);
	stencil_4.setUVy_4Stencil();
	stencil_4.ApplyStencilOperator(begin, end, begin, end, u, branch_4);
	branch_3.MultiplyGridFunctions(begin, end, branch_4);
	output.AddToGridFunction(begin, end, -1.0, branch_3);
	output.ScaleGridFunction(begin, end, 1.0 / h[1]);
//bis hier 1. Zeile
	GridFunction branch_5(u.griddimension);
	Stencil stencil_5(3, h);
	stencil_5.setUVy_5Stencil();
	stencil_5.ApplyStencilOperator(begin, end, begin, end, v, branch_5);

	GridFunction branch_6(u.griddimension);
	Stencil stencil_6(3, h);
	stencil_6.setUVy_6Stencil();
	stencil_6.ApplyStencilOperator(begin, end, begin, end, u, branch_6);
	branch_5.MultiplyGridFunctions(begin, end, branch_6);

	GridFunction branch_7(u.griddimension);
	Stencil stencil_7(3, h);
	stencil_7.setUVy_7Stencil();
	stencil_7.ApplyStencilOperator(begin, end, begin, end, v, branch_7);

	GridFunction branch_8(u.griddimension);
	Stencil stencil_8(3, h);
	stencil_8.setUVy_8Stencil();
	stencil_8.ApplyStencilOperator(begin, end, begin, end, u, branch_8);
	branch_7.MultiplyGridFunctions(begin, end, branch_8);
	branch_5.AddToGridFunction(begin, end, -1.0, branch_7);
	branch_5.ScaleGridFunction(begin, end, alpha * 1.0 / h[1]);
//bis hier 2. Zeile
	output.AddToGridFunction(begin, end, 1.0, branch_5);
}

void Fx(GridFunction& output, GridFunction& f, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = f.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = f.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setFxStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, f, output);

}

void Gy(GridFunction& output, GridFunction& g, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = g.griddimension[0] - 2;
	begin[1] = 1;
	end[1] = g.griddimension[1] - 2;

	Stencil stencil_1(3, h);
	stencil_1.setGyStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, g, output);

}
