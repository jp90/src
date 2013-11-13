/*
 * stencil.cpp
 *
 *  Created on: Nov 12, 2013
 *      Author: jan-philippwolf
 */

#include "gridfunction.h"
#include <iostream>
#include <fstream>


using namespace std;


Stencil::Stencil(int stencilwidth, const PointType& h){
	this->stencilwidth = stencilwidth;
	this->h = h;
	stencil = new RealType*[stencilwidth];

	// Initialize grid values to zero
	for (int i=0;i<stencilwidth;i++){
		stencil[i]=0;
	}
}

void Stencil::~Stencil(){
	 for (int i=0;i<=stencilwidth;i++){
		 delete[]  stencil[i];
	 }
	 delete [] stencil;
}

void Stencil::ApplyStencilOperator(const MultiIndexType& gridreadbegin, const MultiIndexType& gridreadend,
		                           const MultiIndexType gridwritebegin, const MultiIndexType gridwriteend,
		                           Gridfunction sourcegridfunction, Gridfunction imagegridfunction){

	// matrix=sourcegridfunction[gridreadbegin[0]..gridreadend[0]][gridend[1 griendd[1]] 3x3matrix ausgeschnitte aus gitter
	for(int i=gridwritebegin[0];i<gridwriteend[0];i++){
		for(int j=gridwritebegin[1];j<gridwriteend[1];j++){
			RealType sum = 0;

			for(int k=0;k<stencilwidth;k++){
				for(int l=0;l<stencilwidth;l++){
					sum += sourcegridfunction[i-k-(stencilwidth-1)/2][j-l-(stencilwidth-1)/2]*
							stencil[k][l];
				}
			}


			imagegridfunction[i][j] = sum;

	}
	}
	
}
void Stencil::setFxxStencil(){
	stencil[0][1]=1./(h[0]*h[0]);
	stencil[0][2]=1./(h[0]*h[0]);
	stencil[1][1]=-2./(h[0]*h[0]);
}
void Stencil::setFyyStencil(){
	stencil[1][0]=1./(h[1]*h[1]);
	stencil[1][1]=1./(h[1]*h[1]);
	stencil[1][2]=-2./(h[1]*h[1]);
}
void Stencil::setFxStencil(){
	stencil[0][2]=1./h[0];
	stencil[1][1]=-1./h[0];
}
void Stencil::setFFxStencil(){

	stencil[0][1]=1./(h[0]*h[0]);
	stencil[2][1]=1./(h[0]*h[0]);
	stencil[1][1]=-2./(h[0]*h[0]);
}

