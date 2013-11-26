/*
 * derivatives.h
 *
 *  Created on: Nov 14, 2013
 *      Author: jan-philippwolf
 */

#ifndef DERIVATIVES_H_
#define DERIVATIVES_H_

#include "gridfunction.h"
#include "stencil.h"

void Ux(GridFunction& output, GridFunction& u, const PointType& h);

void Uy(GridFunction& output, GridFunction& u, const PointType& h);

void Uxx(GridFunction& output, GridFunction& u, const PointType& h);

void Uyy(GridFunction& output, GridFunction& u, const PointType& h);

void Px(GridFunction& output, GridFunction& u, const PointType& h);

void Py(GridFunction& output, GridFunction& u, const PointType& h);

void Pxx(GridFunction& output, GridFunction& p, const PointType& h);

void Pyy(GridFunction& output, GridFunction& p, const PointType& h);

void Vxx(GridFunction& output, GridFunction& u, const PointType& h);

void Vyy(GridFunction& output, GridFunction& u, const PointType& h);

void UUx(GridFunction& output, GridFunction& u, const RealType alpha,
		const PointType& h);

void VVy(GridFunction& output, GridFunction& u, const RealType alpha,
		const PointType& h);

void UVy(GridFunction& output, GridFunction& u, GridFunction& v,
		const RealType alpha, const PointType& h);
void UVx(GridFunction& output, GridFunction& u, GridFunction& v,
		const RealType alpha, const PointType& h);

void Fx(GridFunction& output, GridFunction& f, const PointType& h);

void Gy(GridFunction& output, GridFunction& g, const PointType& h);

#endif /* DERIVATIVES_H_ */
