/*
 * gridfunction.cpp
 *
 *  Created on: Nov 12, 2013
 *      Author: jan-philippwolf
 */

#include "gridfunction.h"
#include <iostream>
#include <fstream>


using namespace std;


Gridfunction::Gridfunction(int dimX, int dimY){
	grid_dimX = dimX;
	grid_dimY = dimY;
 grid = new RealType*[dimX];
 for (int i=0;i<dimX;i++){
	 grid[i] = new RealType[dimY];
 }
// Initialize grid values to zero
 for (int i=0;i<dimX;i++){
	 for (int j=0;j<dimY;j++){
		 grid[i][j]=0;
	 }
 }
}
Gridfunction::Gridfunction(const MultiIndexType griddimension){
	grid_dimX = griddimension[0];
	grid_dimY = griddimension[1];
	grid = new RealType*[griddimension[0]];
	 for (int i=0;i<griddimension[0];i++){
		 grid[i] = new RealType[griddimension[1]];
	 }
	// Initialize grid values to zero
	 for (int i=0;i<griddimension[0];i++){
		 for (int j=0;j<griddimension[1];j++){
			 grid[i][j]=0;
		 }
	 }
}

Gridfunction::~Gridfunction(){
	 for (int i=0;i<grid_dimX;i++){
		 delete[]  grid[i];
	 }
	 delete [] grid;
}

Gridfunction* Gridfunction::getGridfunction(){
	return this;
}

void Gridfunction::SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType value){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>grid_dimX){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>grid_dimY){cout << "Invalid Index";}
	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 grid[i][j]=value;
		 }
	 }
}

void Gridfunction::SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, MultiIndexType& offset){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>grid_dimX){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>grid_dimY){cout << "Invalid Index";}
	if (begin[0]+offset[0]<0){cout << "Invalid Index";}
	if (begin[0]+offset[0]>grid_dimX){cout << "Invalid Index";}
	if (end[0]+offset[0]<0){cout << "Invalid Index";}
	if (end[0]+offset[0]>grid_dimX){cout << "Invalid Index";}
	if (begin[1]+offset[1]<0){cout << "Invalid Index";}
	if (begin[1]+offset[1]>grid_dimY){cout << "Invalid Index";}
	if (end[1]+offset[1]<0){cout << "Invalid Index";}
	if (end[1]+offset[1]>grid_dimY){cout << "Invalid Index";}


	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 grid[i][j]=factor*grid[i+offset[0]][j+offset[1]];
		 }
	 }
}

void Gridfunction::ScaleGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>grid_dimX){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>grid_dimY){cout << "Invalid Index";}
	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 grid[i][j]*=factor;
		 }
	 }
}

void Gridfunction::SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, Gridfunction& sourcegridfunction){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>grid_dimX){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>grid_dimY){cout << "Invalid Index";}
	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 grid[i][j]=factor*sourcegridfunction.grid[i][j];
		 }
	 }
}

void Gridfunction::SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, Gridfunction& sourcegridfunction, MultiIndexType& offset){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>grid_dimX){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>grid_dimY){cout << "Invalid Index";}
	if (begin[0]+offset[0]<0){cout << "Invalid Index";}
	if (begin[0]+offset[0]>grid_dimX){cout << "Invalid Index";}
	if (end[0]+offset[0]<0){cout << "Invalid Index";}
	if (end[0]+offset[0]>grid_dimX){cout << "Invalid Index";}
	if (begin[1]+offset[1]<0){cout << "Invalid Index";}
	if (begin[1]+offset[1]>grid_dimY){cout << "Invalid Index";}
	if (end[1]+offset[1]<0){cout << "Invalid Index";}
	if (end[1]+offset[1]>grid_dimY){cout << "Invalid Index";}


	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 grid[i][j]=factor*sourcegridfunction.grid[i+offset[0]][j+offset[1]];
		 }
	 }
}
// Mit oder ohne Offset???
void Gridfunction::SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, Gridfunction& sourcegridfunction, MultiIndexType& offset, RealType constant){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>grid_dimX){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>grid_dimY){cout << "Invalid Index";}
	if (begin[0]+offset[0]<0){cout << "Invalid Index";}
	if (begin[0]+offset[0]>grid_dimX){cout << "Invalid Index";}
	if (end[0]+offset[0]<0){cout << "Invalid Index";}
	if (end[0]+offset[0]>grid_dimX){cout << "Invalid Index";}
	if (begin[1]+offset[1]<0){cout << "Invalid Index";}
	if (begin[1]+offset[1]>grid_dimY){cout << "Invalid Index";}
	if (end[1]+offset[1]<0){cout << "Invalid Index";}
	if (end[1]+offset[1]>grid_dimY){cout << "Invalid Index";}


	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 grid[i][j]=factor*sourcegridfunction.grid[i+offset[0]][j+offset[1]]+constant;
		 }
	 }
}

void Gridfunction::AddToGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, Gridfunction& sourcegridfunction){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>grid_dimX){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>grid_dimY){cout << "Invalid Index";}
	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 grid[i][j]+=factor*sourcegridfunction.grid[i][j];
		 }
	 }
}

RealType Gridfunction::MaxValueGridFunction(const MultiIndexType& begin, const MultiIndexType& end){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>grid_dimX){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>grid_dimY){cout << "Invalid Index";}
	RealType max = 0;
	for(int i=begin[0]; i<=begin[1]; i++){
	  for(int j=end[0]; j<=end[1]; j++ ){
		if (grid[i][j]>max) max=grid[i][j];
	  }
	}
	return max;
}
void Gridfunction::Grid_Print(){
	for(int i=0;i<grid_dimX;i++){
		for(int j=0;j<grid_dimX;j++){
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}
