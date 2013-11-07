//============================================================================
// Name        : NumSimFluid.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "IO.hpp"
using namespace std;

int main() {
    char input[] = "./src/inputvals.txt";
    char output[] = "./src/inputvals.txt";
    IO SimIO(input,output);

    cout<<SimIO.para.xLength<<endl;
    cout<<SimIO.para.yLength<<endl;
    cout<<SimIO.para.iMax<<endl;
    cout<<SimIO.para.jMax<<endl;
    cout<<SimIO.para.tEnd<<endl;
    cout<<SimIO.para.deltaT<<endl;
    cout<<SimIO.para.tau<<endl;
    cout<<SimIO.para.deltaVec<<endl;
    cout<<SimIO.para.iterMax<<endl;
    cout<<SimIO.para.eps<<endl;
    cout<<SimIO.para.omg<<endl;
    cout<<SimIO.para.alpha<<endl;
    cout<<SimIO.para.re<<endl;
    cout<<SimIO.para.gx<<endl;
    cout<<SimIO.para.gy<<endl;
    cout<<SimIO.para.ui<<endl;
    cout<<SimIO.para.vi<<endl;
    cout<<SimIO.para.pi<<endl;
	return 0;
}
