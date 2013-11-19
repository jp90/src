/*
 * computation.h
 *
 *  Created on: 12.11.2013
 *      Author: David
 */

#include "gridfunction.h"
#include "derivatives.h"
#include "IO.hpp"

#ifndef COMPUTATION_H_
#define COMPUTATION_H_

class Computation {
public:

	Computation(IO& SimIO);

	RealType computeTimesstep(RealType uMax, RealType vMax);
	void computeNewVelocities(GridFunction& u, GridFunction& v, GridFunction& f,
			GridFunction& g, GridFunction& p, RealType deltaT);

	void computeMomentumEquations(GridFunction& f, GridFunction& g,
			GridFunction& u, GridFunction& v, GridFunction& gx,
			GridFunction& gy, RealType& deltaT);

	void setBoundaryU(GridFunction& u);
	void setBoundaryV(GridFunction& v);
	void setBoundaryP(GridFunction& p);
	void setBoundaryF(GridFunction& f, GridFunction& u);
	void setBoundaryG(GridFunction& g, GridFunction& v);

	void computeRighthandSide(GridFunction& rhs, GridFunction& f, GridFunction& g,RealType deltaT);

	IO SimIO;

};

#endif /* COMPUTATION_H_ */
