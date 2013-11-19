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
	RealType computeResidual(GridFunction& p,
			GridFunction& rhs);
	void SORCycle(GridFunction& p, GridFunction& rhs);

	IO SimIO;
};

#endif /* SOLVER_H_ */
