//! The class implements the IO
/*!
 * @author sina,jp,dave
 * @date 2013
 */

#include "typedef.h"
#include "simparam.h"

#ifndef GRIDFUNCTION_HPP_
#define GRIDFUNCTION_HPP_

#include <iostream>
#include <fstream>

class GridFunction {
public:
	GridFunction(int dimX, int dimY);

	GridFunction(const MultiIndexType griddimension);

	~GridFunction();

	GridFunctionType getGridFunction();

	void SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end,
			RealType value);
	void SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end,
			RealType factor, MultiIndexType& offset);
	void ScaleGridFunction(const MultiIndexType& begin,
			const MultiIndexType& end, RealType factor);
	void SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end,
			RealType factor, GridFunction& sourcegridFunction);
	void SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end,
			RealType factor, GridFunction& sourcegridFunction,
			MultiIndexType& offset);
	void SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end,
			RealType factor, GridFunction& sourcegridFunction,
			MultiIndexType& offset, RealType constant);
	void AddToGridFunction(const MultiIndexType& begin,
			const MultiIndexType& end, RealType factor,
			GridFunction& sourcegridFunction);
	RealType MaxValueGridFunction(const MultiIndexType& begin,
			const MultiIndexType& end);
	void MultiplyGridFunctions(const MultiIndexType& begin,
			const MultiIndexType& end, GridFunction& sourcegridFunction);
	void Grid_Print();

	GridFunctionType gridfunction;
	MultiIndexType griddimension;

};

#endif
