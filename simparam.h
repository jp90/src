/*
 * simparam.h
 *
 *  Created on: Nov 7, 2013
 *      Author: jan-philippwolf
 */

#ifndef SIMPARAM_H_
#define SIMPARAM_H_

struct simparam {
	float xLength;
	float yLength;
	int	  iMax;
	int	  jMax;
	float tEnd;
	float deltaT;
	float tau;
	float deltaVec;
	int   iterMax;
	float eps;
	float omg;
	float alpha;
	float re;
	float gx;
	float gy;
	float ui;
	float vi;
	float pi;
};

#endif /* SIMPARAM_H_ */
