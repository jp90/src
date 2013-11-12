/*
 * computation.h
 *
 *  Created on: 12.11.2013
 *      Author: David
 */

#ifndef COMPUTATION_H_
#define COMPUTATION_H_

class Computation {

	RealType computeTimesstep(RealType uMax, RealType vMax, const PointType& h, RealType Re, RealType tau);
	void computeNewVelocities(GridFunction* u, GridFunction* v);
	void computeMomentumEquations();
	void setBounderyX();
	void computeRighthandSide();





};



#endif /* COMPUTATION_H_ */
