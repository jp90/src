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


Stencil::Stencil(int stencilwidth, const PointType& h) : stencilwidth(){
	
	 stencil = new RealType*[stencilwidth];
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

void Stencil::~Stencil(){
	 for (int i=0;i<=stencilwidth;i++){
		 delete[]  stencil[i];
	 }
	 delete [] stencil;
}

void ApplyStencilOperator(const MultiIndexType& gridreadbegin, const MultiIndexType& gridreadend, const MultiIndexType gridwritebegin, const MultiIndexType gridwriteend, Gridfunction sourcegridfunction, Gridfunction imagegridfunction){
	matrix=sourcegridfunction[gridreadbegin[0]..gridreadend[0]][gridend[1 griendd[1]] 3x3matrix ausgeschnitte aus gitter
	for i=gridwritebegin[0];i<gridwriteend[0]
	for i=gridwritebegin[1];i<gridwriteend[1]
	ableitung[gridwritebegin][gridwriteend]=sourcegridfunction[gridreadbegin][gridreadend]*stencil;
	
}
void setFxxStencil(){
	stencil[0][1]=1./(h[0]*h[0]);
	stencil[2][1]=1./(h[0]*h[0]);
	stencil[1][1]=-2./(h[0]*h[0]);
}
void setFyyStencil(){
	stencil[1][0]=1./(h[1]*h[1]);
	stencil[1][2]=1./(h[1]*h[1]);
	stencil[1][1]=-2./(h[1]*h[1]);
}
void setFxStencil(){
	stencil[2][1]=1./h[0];
	stencil[1][1]=-1./h[0];
}
void setFFxStencil(){

	stencil[0][1]=1./(h[0]*h[0]);
	stencil[2][1]=1./(h[0]*h[0]);
	stencil[1][1]=-2./(h[0]*h[0]);
}

