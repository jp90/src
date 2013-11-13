/*
 * stencil.cpp
 *
 *  Created on: Nov 12, 2013
 *      Author: jan-philippwolf
 */

#include "gridfunction.h"
#include "stencil.h"
#include <iostream>
#include <fstream>


using namespace std;


Stencil::Stencil(int stencilwidth, const PointType& h) : h(h) {
	this->stencilwidth = stencilwidth;

	stencil = new RealType* [stencilwidth];
	 for (int i=0;i<stencilwidth;i++){
		 stencil[i] = new RealType[stencilwidth];
	 }
	// Initialize grid values to zero
	 for (int i=0;i<stencilwidth;i++){
		 for (int j=0;j<stencilwidth;j++){
			 stencil[i][j]=0;
		 }
	 }
}

Stencil::~Stencil(){
//	 for (int i=0;i<=stencilwidth;i++){
//		 delete[] stencil[i];
//	 }

}

void Stencil::ApplyStencilOperator(const MultiIndexType& gridreadbegin, const MultiIndexType& gridreadend,
		                           const MultiIndexType& gridwritebegin, const MultiIndexType& gridwriteend,
		                           Gridfunction sourcegridfunction, Gridfunction imagegridfunction){
	sourcegridfunction.Grid_Print();
	int a =int((stencilwidth-1)/2);

	for(int i=gridwritebegin[0];i<gridwriteend[0];i++){
		for(int j=gridwritebegin[1];j<gridwriteend[1];j++){
			RealType sum = 0.0;
			//sum = sum + 1.0;
			for(int k=0;k<stencilwidth;k++){
				for(int l=0;l<stencilwidth;l++){
					//sum += sourcegridfunction.getGridfunction()[i-k-int((stencilwidth-1)/2)]
					//                                           [j-l-int((stencilwidth-1)/2)]*stencil[k][l];
					sum += sourcegridfunction.getGridfunction()[i+k-a][j+l-a]*stencil[k][l];


				}
			}

		imagegridfunction.getGridfunction()[i][j] = sum;
	}
	}

}
void Stencil::setFxxStencil(){
	stencil[0][1]=1.0/(h[0]*h[0]);
	stencil[0][2]=1.0/(h[0]*h[0]);
	stencil[1][1]=-2.0/(h[0]*h[0]);
}
void Stencil::setFyyStencil(){
	stencil[1][0]=1.0/(h[1]*h[1]);
	stencil[1][1]=1.0/(h[1]*h[1]);
	stencil[1][2]=-2.0/(h[1]*h[1]);
}
void Stencil::setFxStencil(){
	stencil[0][2]=1.0/h[0];
	stencil[1][1]=-1.0/h[0];
}


