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
	void Stencil::setFFx_1Stencil();
	void Stencil::setFFx_2Stencil();
	void Stencil::setFFx_3Stencil();
	void Stencil::setFFx_4Stencil();
	void Stencil::setFFx_5Stencil();
	void Stencil::setFFx_6Stencil();

StencilType stencil;
int stencilwidth;
const PointType& h;

bool abs;


};
#endif /* STENCIL_H_ */
