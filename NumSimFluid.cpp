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
using namespace std;

int main() {
    char input[] = "./src/inputvals.txt";
    char output[] = "./src/inputvals.txt";
    IO SimIO(input,output);
    Gridfunction Gitter(10,10);
    Gridfunction Ableitungen(10,10);
    MultiIndexType begin, end, offset, gridreadbegin, gridreadend, gridwritebegin, gridwriteend;
    begin[0]=1;
    end[0]=1;
    begin[1]=2;
    end[1]=8;
    offset[0]=1;
    offset[1]=3;
    PointType h;
    h[0]=0.1;
    h[1]=0.1;
    Stencil stenc(3,h);
    stenc.setFxStencil();
    Gitter.SetGridFunction(begin,end,4.0);
    Gitter.Grid_Print();
    cout << endl;
    gridreadbegin[0]=1;
    gridreadbegin[1]=1;
    gridreadend[0]=8;
    gridreadend[0]=8;
    gridwritebegin[0]=1;
    gridwritebegin[1]=1;
    gridwriteend[0]=8;
    gridwriteend[1]=8;

    stenc.ApplyStencilOperator(gridreadbegin, gridreadend, gridwritebegin, gridwriteend,Gitter, Ableitungen);


  //  Ableitungen.Grid_Print();
	cout <<"test";
    return 0;
}
