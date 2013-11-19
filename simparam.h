/*
 * simparam.h
 *
 *  Created on: Nov 7, 2013
 *      Author: jan-philippwolf
 */

#include "typedef.h"

#ifndef SIMPARAM_H_
#define SIMPARAM_H_

struct simparam {
	RealType xLength;
	RealType yLength;
	int	  iMax;
	int	  jMax;
	RealType tEnd;
	RealType deltaT;
	RealType deltaX;
	RealType deltaY;
	RealType tau;
	RealType deltaVec;
	int   iterMax;
	RealType eps;
	RealType omg;
	RealType alpha;
	RealType re;
	RealType gx;
	RealType gy;
	RealType ui;
	RealType vi;
	RealType pi;
};

#endif /* SIMPARAM_H_ */
