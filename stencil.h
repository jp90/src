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
	void setFxStencil();
	void setFyStencil();
	void setFxxStencil();
	void setFyyStencil();

	void setFFx_1Stencil();
	void setFFx_2Stencil();
	void setFFx_3Stencil();
	void setFFx_4Stencil();
	void setFFx_5Stencil();
	void setFFx_6Stencil();

	void setFFy_1Stencil();
	void setFFy_2Stencil();
	void setFFy_3Stencil();
	void setFFy_4Stencil();
	void setFFy_5Stencil();
	void setFFy_6Stencil();

	void setFGx_1Stencil();
	void setFGx_2Stencil();
	void setFGx_3Stencil();
	void setFGx_4Stencil();
	void setFGx_5Stencil();
	void setFGx_6Stencil();
	void setFGx_7Stencil();
	void setFGx_8Stencil();

	void setFGy_1Stencil();
	void setFGy_2Stencil();
	void setFGy_3Stencil();
	void setFGy_4Stencil();
	void setFGy_5Stencil();
	void setFGy_6Stencil();
	void setFGy_7Stencil();
	void setFGy_8Stencil();
StencilType stencil;
int stencilwidth;
const PointType& h;

bool abs;


};
#endif /* STENCIL_H_ */
