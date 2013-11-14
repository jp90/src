/*
 * computation.cpp
 *
 *  Created on: 12.11.2013
 *      Author: David
 */

#include "computation.h"


	RealType Computation::computeTimesstep(RealType uMax, RealType vMax, const PointType& h, RealType Re, RealType tau){

		return 0.0;
	}
	void Computation::computeNewVelocities(Gridfunction* u, Gridfunction* v, GridFunctionType& f, GridFunctionType& g,
			                     GridFunctionType& p, const PointType& delta, RealType deltaT){


	}


	void Computation::computeMomentumEquations(Gridfunction* f, GridFunctionType* g, GridFunctionType* u,
									 GridFunctionType* v, GridFunctionType& gx, GridFunctionType& gy,
									 const PointType& h, RealType deltaT){



	}

	void Computation::setBounderyX(Gridfunction x){



	}
	void Computation::computeRighthandSide(const MultiIndexType& griddimension, GridFunctionType& rhs, GridFunctionType& f,
		                        GridFunctionType& g, const PointType& delta, RealType deltaT){



	}



