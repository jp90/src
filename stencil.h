/*
 * stencil.h
 *
 *  Created on: Nov 12, 2013
 *      Author: jan-philippwolf
 */

#ifndef STENCIL_H_
#define STENCIL_H_

#include "gridfunction.h"

class Stencil{
public:
	Stencil(int stencilwidth, const PointType& h);

	void ~Stencil();
	void ApplyStencilOperator(const MultiIndexType& gridreadbegin, const MultiIndexType& gridreadend, const MultiIndexType gridwritebegin, const MultiIndexType gridwriteend, Gridfunction sourcegridfunction, Gridfunction imagegridfunction);
	void setFxxStencil();
StencilType stencil;
int stencilwidth;
const PointType& h;
};
#endif /* STENCIL_H_ */
