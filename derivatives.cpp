/* * derivatives.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: jan-philippwolf
 */
#include "derivatives.h"

Gridfunction Ux(const MultiIndexType& dimension, Gridfunction& u,
		const RealType alpha, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = dimension[0] - 2;
	begin[1] = 1;
	end[1] = dimension[1] - 2;

	Gridfunction branch_1(dimension);
	Stencil stencil_1(3, h);
	stencil_1.setUxStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, u, branch_1);

	return branch_1;

}

Gridfunction Uy(const MultiIndexType& dimension, Gridfunction& u,
		const RealType alpha, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = dimension[0] - 2;
	begin[1] = 1;
	end[1] = dimension[1] - 2;

	Gridfunction branch_1(dimension);
	Stencil stencil_1(3, h);
	stencil_1.setUyStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, u, branch_1);

	return branch_1;

}

Gridfunction Uxx(const MultiIndexType& dimension, Gridfunction& u,
		const RealType alpha, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = dimension[0] - 2;
	begin[1] = 1;
	end[1] = dimension[1] - 2;

	Gridfunction branch_1(dimension);
	Stencil stencil_1(3, h);
	stencil_1.setUxxStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, u, branch_1);

	return branch_1;

}

Gridfunction Uyy(const MultiIndexType& dimension, Gridfunction& u,
		const RealType alpha, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = dimension[0] - 2;
	begin[1] = 1;
	end[1] = dimension[1] - 2;

	Gridfunction branch_1(dimension);
	Stencil stencil_1(3, h);
	stencil_1.setUyyStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, u, branch_1);

	return branch_1;

}

Gridfunction Px(const MultiIndexType& dimension, Gridfunction& p,
		const RealType alpha, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = dimension[0] - 2;
	begin[1] = 1;
	end[1] = dimension[1] - 2;

	Gridfunction branch_1(dimension);
	Stencil stencil_1(3, h);
	stencil_1.setPxStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, p, branch_1);

	return branch_1;

}

Gridfunction Vxx(const MultiIndexType& dimension, Gridfunction& v,
		const RealType alpha, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = dimension[0] - 2;
	begin[1] = 1;
	end[1] = dimension[1] - 2;

	Gridfunction branch_1(dimension);
	Stencil stencil_1(3, h);
	stencil_1.setUxxStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, v, branch_1);

	return branch_1;

}

Gridfunction Vyy(const MultiIndexType& dimension, Gridfunction& v,
		const RealType alpha, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = dimension[0] - 2;
	begin[1] = 1;
	end[1] = dimension[1] - 2;

	Gridfunction branch_1(dimension);
	Stencil stencil_1(3, h);
	stencil_1.setUyyStencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, v, branch_1);

	return branch_1;

}

Gridfunction UUx(const MultiIndexType& dimension, Gridfunction& u,
		const RealType alpha, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = dimension[0] - 2;
	begin[1] = 1;
	end[1] = dimension[1] - 2;

	Gridfunction branch_1(dimension);
	Stencil stencil_1(3, h);
	stencil_1.setUUx_1Stencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, u, branch_1);
	branch_1.MultiplyGridFunctions(begin, end, branch_1);

	Gridfunction branch_2(dimension);
	Stencil stencil_2(3, h);
	stencil_2.setUUx_2Stencil();
	stencil_2.ApplyStencilOperator(begin, end, begin, end, u, branch_2);
	branch_2.MultiplyGridFunctions(begin, end, branch_2);

	branch_1.AddToGridFunction(begin, end, -1.0, branch_2);
	branch_1.ScaleGridFunction(begin, end, 1.0 / h[0]);

	Gridfunction branch_3(dimension);
	Stencil stencil_3(3, h);
	stencil_3.setUUx_3Stencil();
	stencil_3.ApplyStencilOperator(begin, end, begin, end, u, branch_3);
	branch_3.MultiplyGridFunctions(begin, end, branch_3);

	Gridfunction branch_4(dimension);
	Stencil stencil_4(3, h);
	stencil_4.setUUx_4Stencil();
	stencil_4.ApplyStencilOperator(begin, end, begin, end, u, branch_4);
	branch_4.MultiplyGridFunctions(begin, end, branch_4);

	branch_3.MultiplyGridFunctions(begin, end, branch_4);

	Gridfunction branch_5(dimension);
	Stencil stencil_5(3, h);
	stencil_5.setUUx_5Stencil();
	stencil_5.ApplyStencilOperator(begin, end, begin, end, u, branch_5);
	branch_5.MultiplyGridFunctions(begin, end, branch_5);

	Gridfunction branch_6(dimension);
	Stencil stencil_6(3, h);
	stencil_6.setUUx_6Stencil();
	stencil_6.ApplyStencilOperator(begin, end, begin, end, u, branch_6);
	branch_6.MultiplyGridFunctions(begin, end, branch_6);

	branch_5.MultiplyGridFunctions(begin, end, branch_6);

	branch_3.AddToGridFunction(begin, end, -1.0, branch_5);

	branch_3.ScaleGridFunction(begin, end, alpha / h[0]);

	branch_1.AddToGridFunction(begin, end, 1.0, branch_3);

	return branch_1;

}

Gridfunction VVy(const MultiIndexType& dimension, Gridfunction& v,
		const RealType alpha, const PointType& h) {

	MultiIndexType begin, end;

	begin[0] = 1;
	end[0] = dimension[0] - 2;
	begin[1] = 1;
	end[1] = dimension[1] - 2;

	Gridfunction branch_1(dimension);
	Stencil stencil_1(3, h);
	stencil_1.setVVy_1Stencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, v, branch_1);
	branch_1.MultiplyGridFunctions(begin, end, branch_1);

	Gridfunction branch_2(dimension);
	Stencil stencil_2(3, h);
	stencil_2.setVVy_2Stencil();
	stencil_2.ApplyStencilOperator(begin, end, begin, end, v, branch_2);
	branch_2.MultiplyGridFunctions(begin, end, branch_2);

	branch_1.AddToGridFunction(begin, end, -1.0, branch_2);
	branch_1.ScaleGridFunction(begin, end, 1.0 / h[1]);

	Gridfunction branch_3(dimension);
	Stencil stencil_3(3, h);
	stencil_3.setVVy_3Stencil();
	stencil_3.ApplyStencilOperator(begin, end, begin, end, v, branch_3);
	branch_3.MultiplyGridFunctions(begin, end, branch_3);

	Gridfunction branch_4(dimension);
	Stencil stencil_4(3, h);
	stencil_4.setVVy_4Stencil();
	stencil_4.ApplyStencilOperator(begin, end, begin, end, v, branch_4);
	branch_4.MultiplyGridFunctions(begin, end, branch_4);

	branch_3.MultiplyGridFunctions(begin, end, branch_4);

	Gridfunction branch_5(dimension);
	Stencil stencil_5(3, h);
	stencil_5.setVVy_5Stencil();
	stencil_5.ApplyStencilOperator(begin, end, begin, end, v, branch_5);
	branch_5.MultiplyGridFunctions(begin, end, branch_5);

	Gridfunction branch_6(dimension);
	Stencil stencil_6(3, h);
	stencil_6.setVVy_6Stencil();
	stencil_6.ApplyStencilOperator(begin, end, begin, end, v, branch_6);
	branch_6.MultiplyGridFunctions(begin, end, branch_6);

	branch_5.MultiplyGridFunctions(begin, end, branch_6);

	branch_3.AddToGridFunction(begin, end, -1.0, branch_5);

	branch_3.ScaleGridFunction(begin, end, alpha / h[1]);

	branch_1.AddToGridFunction(begin, end, 1.0, branch_3);

	return branch_1;

}

Gridfunction UVx(const MultiIndexType& dimension, Gridfunction& u,
		Gridfunction& v, const RealType alpha, const PointType& h) {
	MultiIndexType begin, end;
	begin[0] = 1;
	end[0] = dimension[0] - 2;
	begin[1] = 1;
	end[1] = dimension[1] - 2;

	Gridfunction branch_1(dimension);
	Stencil stencil_1(3, h);
	stencil_1.setUVx_1Stencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, u, branch_1);

	Gridfunction branch_2(dimension);
	Stencil stencil_2(3, h);
	stencil_2.setUVx_2Stencil();
	stencil_2.ApplyStencilOperator(begin, end, begin, end, v, branch_2);
	branch_1.MultiplyGridFunctions(begin, end, branch_2);

	Gridfunction branch_3(dimension);
	Stencil stencil_3(3, h);
	stencil_3.setUVx_3Stencil();
	stencil_3.ApplyStencilOperator(begin, end, begin, end, u, branch_3);

	Gridfunction branch_4(dimension);
	Stencil stencil_4(3, h);
	stencil_4.setUVx_4Stencil();
	stencil_4.ApplyStencilOperator(begin, end, begin, end, v, branch_4);
	branch_3.MultiplyGridFunctions(begin, end, branch_4);
	branch_1.AddToGridFunction(begin, end, -1.0, branch_3);
	branch_1.ScaleGridFunction(begin, end, 1.0 / h[0]);
//bis hier 1. Zeile
	Gridfunction branch_5(dimension);
	Stencil stencil_5(3, h);
	stencil_5.setUVx_5Stencil();
	stencil_5.ApplyStencilOperator(begin, end, begin, end, u, branch_5);

	Gridfunction branch_6(dimension);
	Stencil stencil_6(3, h);
	stencil_6.setUVx_6Stencil();
	stencil_6.ApplyStencilOperator(begin, end, begin, end, v, branch_6);
	branch_5.MultiplyGridFunctions(begin, end, branch_6);

	Gridfunction branch_7(dimension);
	Stencil stencil_7(3, h);
	stencil_7.setUVx_7Stencil();
	stencil_7.ApplyStencilOperator(begin, end, begin, end, u, branch_7);

	Gridfunction branch_8(dimension);
	Stencil stencil_8(3, h);
	stencil_8.setUVx_8Stencil();
	stencil_8.ApplyStencilOperator(begin, end, begin, end, v, branch_8);
	branch_7.MultiplyGridFunctions(begin, end, branch_8);
	branch_5.AddToGridFunction(begin, end, -1.0, branch_7);
	branch_5.ScaleGridFunction(begin, end, alpha * 1.0 / h[0]);
//bis hier 2. Zeile
	branch_1.AddToGridFunction(begin, end, 1.0, branch_5);
	return branch_1;
}

Gridfunction UVy(const MultiIndexType& dimension, Gridfunction& u,
		Gridfunction& v, const RealType alpha, const PointType& h) {
	MultiIndexType begin, end;
	begin[0] = 1;
	end[0] = dimension[0] - 2;
	begin[1] = 1;
	end[1] = dimension[1] - 2;

	Gridfunction branch_1(dimension);
	Stencil stencil_1(3, h);
	stencil_1.setUVy_1Stencil();
	stencil_1.ApplyStencilOperator(begin, end, begin, end, v, branch_1);
	Gridfunction branch_2(dimension);
	Stencil stencil_2(3, h);
	stencil_2.setUVy_2Stencil();
	stencil_2.ApplyStencilOperator(begin, end, begin, end, u, branch_2);
	branch_1.MultiplyGridFunctions(begin, end, branch_2);

	Gridfunction branch_3(dimension);
	Stencil stencil_3(3, h);
	stencil_3.setUVy_3Stencil();
	stencil_3.ApplyStencilOperator(begin, end, begin, end, v, branch_3);

	Gridfunction branch_4(dimension);
	Stencil stencil_4(3, h);
	stencil_4.setUVy_4Stencil();
	stencil_4.ApplyStencilOperator(begin, end, begin, end, u, branch_4);
	branch_3.MultiplyGridFunctions(begin, end, branch_4);
	branch_1.AddToGridFunction(begin, end, -1.0, branch_3);
	branch_1.ScaleGridFunction(begin, end, 1.0 / h[1]);
//bis hier 1. Zeile
	Gridfunction branch_5(dimension);
	Stencil stencil_5(3, h);
	stencil_5.setUVy_5Stencil();
	stencil_5.ApplyStencilOperator(begin, end, begin, end, v, branch_5);

	Gridfunction branch_6(dimension);
	Stencil stencil_6(3, h);
	stencil_6.setUVy_6Stencil();
	stencil_6.ApplyStencilOperator(begin, end, begin, end, u, branch_6);
	branch_5.MultiplyGridFunctions(begin, end, branch_6);

	Gridfunction branch_7(dimension);
	Stencil stencil_7(3, h);
	stencil_7.setUVy_7Stencil();
	stencil_7.ApplyStencilOperator(begin, end, begin, end, v, branch_7);

	Gridfunction branch_8(dimension);
	Stencil stencil_8(3, h);
	stencil_8.setUVy_8Stencil();
	stencil_8.ApplyStencilOperator(begin, end, begin, end, u, branch_8);
	branch_7.MultiplyGridFunctions(begin, end, branch_8);
	branch_5.AddToGridFunction(begin, end, -1.0, branch_7);
	branch_5.ScaleGridFunction(begin, end, alpha * 1.0 / h[1]);
//bis hier 2. Zeile
	branch_1.AddToGridFunction(begin, end, 1.0, branch_5);
	return branch_1;
}

