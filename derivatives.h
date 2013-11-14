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

Gridfunction Uxx(const MultiIndexType& dimension, Gridfunction& u,
		const RealType alpha, const PointType& h);

Gridfunction Uyy(const MultiIndexType& dimension, Gridfunction& u,
		const RealType alpha, const PointType& h);

Gridfunction Px(const MultiIndexType& dimension, Gridfunction& u,
		const RealType alpha, const PointType& h);

Gridfunction Vxx(const MultiIndexType& dimension, Gridfunction& u,
		const RealType alpha, const PointType& h);

Gridfunction Vyy(const MultiIndexType& dimension, Gridfunction& u,
		const RealType alpha, const PointType& h);

Gridfunction UUx(const MultiIndexType& dimension, Gridfunction& u,
		const RealType alpha, const PointType& h);

Gridfunction VVy(const MultiIndexType& dimension, Gridfunction& u,
		const RealType alpha, const PointType& h);

Gridfunction UVy(const MultiIndexType& dimension, Gridfunction& u,
		Gridfunction& v, const RealType alpha, const PointType& h);
Gridfunction UVx(const MultiIndexType& dimension, Gridfunction& u,
		Gridfunction& v, const RealType alpha, const PointType& h);

#endif /* DERIVATIVES_H_ */
