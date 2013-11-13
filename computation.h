/*
 * computation.h
 *
 *  Created on: 12.11.2013
 *      Author: David
 */

#include "gridfunction.h"

#ifndef COMPUTATION_H_
#define COMPUTATION_H_

class Computation {

	RealType computeTimesstep(RealType uMax, RealType vMax, const PointType& h, RealType Re, RealType tau);
	void computeNewVelocities(Gridfunction* u, Gridfunction* v, GridFunctionType& f, GridFunctionType& g,
			                     GridFunctionType& p, const PointType& delta, RealType deltaT);

	void computeMomentumEquations(Gridfunction* f, GridFunctionType* g, GridFunctionType* u,
									 GridFunctionType* v, GridFunctionType& gx, GridFunctionType& gy,
									 const PointType& h, RealType deltaT);

	void setBounderyX(Gridfunction x);
	void computeRighthandSide(const MultiIndexType& griddimension, GridFunctionType& rhs, GridFunctionType& f,
		                        GridFunctionType& g, const PointType& delta, RealType deltaT);





};



#endif /* COMPUTATION_H_ */
