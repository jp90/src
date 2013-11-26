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

class Stencil {
public:
	Stencil(int stencilwidth, const PointType& h);

	~Stencil();
	void ApplyStencilOperator(const MultiIndexType& gridreadbegin,
			const MultiIndexType& gridreadend,
			const MultiIndexType& gridwritebegin,
			const MultiIndexType& gridwriteend,
			GridFunction& sourcegridFunction, GridFunction& imagegridFunction);
	void setUxStencil();
	void setUyStencil();
	void setPxStencil();
	void setPyStencil();
	void setPxxStencil();
	void setPyyStencil();
	void setUxxStencil();
	void setUyyStencil();

	void setUUx_1Stencil();
	void setUUx_2Stencil();
	void setUUx_3Stencil();
	void setUUx_4Stencil();
	void setUUx_5Stencil();
	void setUUx_6Stencil();

	void setVVy_1Stencil();
	void setVVy_2Stencil();
	void setVVy_3Stencil();
	void setVVy_4Stencil();
	void setVVy_5Stencil();
	void setVVy_6Stencil();

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

	void setFxStencil();
	void setGyStencil();

	StencilType stencil;
	int stencilwidth;
	const PointType& h;

	bool abs;

};
#endif /* STENCIL_H_ */
