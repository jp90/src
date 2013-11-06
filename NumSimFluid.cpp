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
	return 0;
}
