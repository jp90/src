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

class Gridfunction{
public:
	Gridfunction(int dimX, int dimY);

	Gridfunction(const MultiIndexType griddimension);

	~Gridfunction();

	GridFunctionType getGridfunction();

	void SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType value);
	void SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, MultiIndexType& offset);
	void ScaleGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor);
	void SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, Gridfunction& sourcegridfunction);
	void SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, Gridfunction& sourcegridfunction, MultiIndexType& offset);
	void SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, Gridfunction& sourcegridfunction, MultiIndexType& offset, RealType constant);
	void AddToGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, Gridfunction& sourcegridfunction);
	RealType MaxValueGridFunction(const MultiIndexType& begin, const MultiIndexType& end);
	void MultiplyGridFunctions(const MultiIndexType& begin, const MultiIndexType& end, Gridfunction& sourcegridfunction);
	void Grid_Print();


	GridFunctionType gridfunction;
	MultiIndexType griddimension;

};


#endif
