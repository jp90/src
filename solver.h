/*
 * solver.h
 *
 *  Created on: 12.11.2013
 *      Author: David
 */
#include "gridfunction.h"
#include "IO.hpp"
#include "derivatives.h"

#ifndef SOLVER_H_
#define SOLVER_H_

class Solver {
public:

	Solver(IO& SimIO);
	RealType computeResidual(GridFunction& sourcegridfunction,
			GridFunction& rhs);
	void SORCycle(GridFunction* gridfunction, GridFunctionType& rhs,
			const PointType& delta, RealType omega);

	IO SimIO;
};

#endif /* SOLVER_H_ */
