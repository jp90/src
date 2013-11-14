//============================================================================
// Name        : NumSimFluid.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "IO.hpp"
#include "gridfunction.h"
#include "stencil.h"
#include "derivatives.h"
using namespace std;

int main() {
	char input[] = "./src/inputvals.txt";
	char output[] = "./src/inputvals.txt";
	IO SimIO(input, output);

	MultiIndexType begin, end, offset, gridreadbegin, gridreadend,
			gridwritebegin, gridwriteend;

	PointType h;
	h[0] = 1.0;
	h[1] = 1.0;
	MultiIndexType dim;
	dim[0] = 20;
	dim[1] = 20;
	Gridfunction u(dim);
	begin[0] = 0;
	end[0] = 19;
	begin[1] = 0;
	end[1] = 19;

	u.SetGridFunction(begin, end, 4.0);

	begin[0] = 5;
	end[0] = 12;
	begin[1] = 3;
	end[1] = 15;

	u.SetGridFunction(begin, end, 2.0);

	begin[0] = 1;
	end[0] = 18;
	begin[1] = 1;
	end[1] = 18;
	RealType alpha = 1.0;
	Gridfunction FFX = Uy(dim, u, alpha, h);

	u.Grid_Print();
	cout << endl;
	FFX.Grid_Print();
}
