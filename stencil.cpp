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

	abs=false;

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
	 for (int i=0;i<stencilwidth;i++){
		 delete[] stencil[i];
	 }
    delete[] stencil;
}

void Stencil::ApplyStencilOperator(const MultiIndexType& gridreadbegin, const MultiIndexType& gridreadend,
		                           const MultiIndexType& gridwritebegin, const MultiIndexType& gridwriteend,
		                           Gridfunction& sourcegridfunction, Gridfunction& imagegridfunction){
	int a =int((stencilwidth-1)/2);

	for(int i=gridwritebegin[0];i<gridwriteend[0];i++){
		for(int j=gridwritebegin[1];j<gridwriteend[1];j++){
			RealType sum = 0.0;
			for(int k=0;k<stencilwidth;k++){
				for(int l=0;l<stencilwidth;l++){
					//sum += sourcegridfunction.getGridfunction()[i-k-int((stencilwidth-1)/2)]
					//                                           [j-l-int((stencilwidth-1)/2)]*stencil[k][l];
					sum += sourcegridfunction.getGridfunction()[i+k-a][j+l-a]*stencil[k][l];


				}
			}
          if(abs) {
        	  if(sum<0.0)sum=-1.0*(sum);
          }
		imagegridfunction.getGridfunction()[i][j] = sum;
	}
	}

}
void Stencil::setFxStencil(){
	stencil[2][1]=1.0/h[0];
	stencil[1][1]=-1.0/h[0];
}
void Stencil::setFyStencil(){
	stencil[1][1]=-1.0/h[0];
	stencil[1][2]=1.0/h[0];
}
void Stencil::setFxxStencil(){
	stencil[0][1]=1.0/(h[0]*h[0]);
	stencil[1][1]=-2.0/(h[0]*h[0]);
	stencil[2][1]=1.0/(h[0]*h[0]);
}
void Stencil::setFyyStencil(){
	stencil[1][0]=1.0/(h[1]*h[1]);
	stencil[1][1]=-2.0/(h[1]*h[1]);
	stencil[1][2]=1.0/(h[1]*h[1]);
}
// Stencils for Derivative d/dx (u^2)
void Stencil::setFFx_1Stencil(){
	stencil[1][1]=1/2;
	stencil[2][1]=1/2;
}
void Stencil::setFFx_2Stencil(){
	stencil[1][1]=1/2;
	stencil[0][1]=1/2;
}
void Stencil::setFFx_3Stencil(){
	abs = true;
	stencil[1][1]=1/2;
	stencil[2][1]=1/2;
}
void Stencil::setFFx_4Stencil(){
	stencil[1][1]=1/2;
	stencil[2][1]=-1/2;
}
void Stencil::setFFx_5Stencil(){
	abs = true;
	stencil[1][1]=1/2;
	stencil[0][1]=1/2;
}
void Stencil::setFFx_6Stencil(){
	stencil[1][1]=-1/2;
	stencil[0][1]=1/2;
}
