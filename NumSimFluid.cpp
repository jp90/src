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
using namespace std;

int main() {
    char input[] = "./src/inputvals.txt";
    char output[] = "./src/inputvals.txt";
    IO SimIO(input,output);
    Gridfunction Gitter(10,10);
    MultiIndexType begin, end, offset;
    begin[0]=1;
    end[0]=1;
    begin[1]=2;
    end[1]=8;
    offset[0]=1;
    offset[1]=3;
    RealType factor=3;

    Gitter.SetGridFunction(begin,end,4.0);
    Gitter.Grid_Print();
    Gitter.SetGridFunction(begin,end,4.0,offset);

    Gitter.Grid_Print();
	return 0;
}
