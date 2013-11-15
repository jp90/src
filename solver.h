/*
 * solver.h
 *
 *  Created on: 12.11.2013
 *      Author: David
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include "gridfunction.h"

class Solver {

     RealType computeResidual(GridFunctionType& sourcegridfunction, GridFunctionType& rhs,
    		                     const PointType& h);
     void SORCycle(GridFunction* gridfunction, GridFunctionType& rhs, const PointType& delta,
    		          RealType omega);

};



#endif /* SOLVER_H_ */
