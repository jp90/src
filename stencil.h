/*
 * stencil.h
 *
 *  Created on: Nov 12, 2013
 *      Author: jan-philippwolf
 */

#ifndef STENCIL_H_
#define STENCIL_H_

#include "gridfunction.h"
#include "typedef.h"

class Stencil{
public:
	Stencil(int stencilwidth, const PointType& h);

    ~Stencil();
	void ApplyStencilOperator(const MultiIndexType& gridreadbegin, const MultiIndexType& gridreadend,
			                  const MultiIndexType& gridwritebegin, const MultiIndexType& gridwriteend,
		                      Gridfunction& sourcegridfunction, Gridfunction& imagegridfunction);
	void setUxStencil();
	void setUyStencil();
	void setUxxStencil();
	void setUyyStencil();

	void setUUx_1Stencil();
	void setUUx_2Stencil();
	void setUUx_3Stencil();
	void setUUx_4Stencil();
	void setUUx_5Stencil();
	void setUUx_6Stencil();

	void setUUy_1Stencil();
	void setUUy_2Stencil();
	void setUUy_3Stencil();
	void setUUy_4Stencil();
	void setUUy_5Stencil();
	void setUUy_6Stencil();

	void setUVx_1Stencil();
	void setUVx_2Stencil();
	void setUVx_3Stencil();
	void setUVx_4Stencil();
	void setUVx_5Stencil();
	void setUVx_6Stencil();
	void setUVx_7Stencil();
	void setUVx_8Stencil();

	void setUVy_1Stencil();
	void setUVy_2Stencil();
	void setUVy_3Stencil();
	void setUVy_4Stencil();
	void setUVy_5Stencil();
	void setUVy_6Stencil();
	void setUVy_7Stencil();
	void setUVy_8Stencil();
StencilType stencil;
int stencilwidth;
const PointType& h;

bool abs;


};
#endif /* STENCIL_H_ */
