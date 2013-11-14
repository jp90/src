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

Gridfunction UUx(const MultiIndexType& dimension,
		          Gridfunction& u,const RealType alpha,const PointType& h);




#endif /* DERIVATIVES_H_ */
