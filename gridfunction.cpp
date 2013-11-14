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
	griddimension[0] = dimX;
	griddimension[1] = dimY;
	gridfunction = new RealType*[dimX];
 for (int i=0;i<dimX;i++){
	 gridfunction[i] = new RealType[dimY];
 }
// Initialize grid values to zero
 for (int i=0;i<dimX;i++){
	 for (int j=0;j<dimY;j++){
		 gridfunction[i][j]=0;
	 }
 }
}
Gridfunction::Gridfunction(const MultiIndexType griddimension){
	this->griddimension[0] = griddimension[0];
	this->griddimension[1] = griddimension[1];
	gridfunction = new RealType*[griddimension[0]];
	 for (int i=0;i<griddimension[0];i++){
		 gridfunction[i] = new RealType[griddimension[1]];
	 }
	// Initialize grid values to zero
	 for (int i=0;i<griddimension[0];i++){
		 for (int j=0;j<griddimension[1];j++){
			 gridfunction[i][j]=0;
		 }
	 }
}

Gridfunction::~Gridfunction(){
	 for (int i=0;i<griddimension[0];i++)
		delete [] gridfunction[i];
	 delete [] gridfunction;
}

GridFunctionType Gridfunction::getGridfunction(){
	return gridfunction;
}

void Gridfunction::SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType value){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>griddimension[0]){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>griddimension[1]){cout << "Invalid Index";}
	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 gridfunction[i][j]=value;
		 }
	 }
}

void Gridfunction::SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, MultiIndexType& offset){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>griddimension[0]){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>griddimension[1]){cout << "Invalid Index";}
	if (begin[0]+offset[0]<0){cout << "Invalid Index";}
	if (begin[0]+offset[0]>griddimension[0]){cout << "Invalid Index";}
	if (end[0]+offset[0]<0){cout << "Invalid Index";}
	if (end[0]+offset[0]>griddimension[0]){cout << "Invalid Index";}
	if (begin[1]+offset[1]<0){cout << "Invalid Index";}
	if (begin[1]+offset[1]>griddimension[1]){cout << "Invalid Index";}
	if (end[1]+offset[1]<0){cout << "Invalid Index";}
	if (end[1]+offset[1]>griddimension[1]){cout << "Invalid Index";}


	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 gridfunction[i][j]=factor*gridfunction[i+offset[0]][j+offset[1]];
		 }
	 }
}

void Gridfunction::ScaleGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>griddimension[0]){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>griddimension[1]){cout << "Invalid Index";}
	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 gridfunction[i][j]*=factor;
		 }
	 }
}

void Gridfunction::SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, Gridfunction& sourcegridfunction){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>griddimension[0]){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>griddimension[1]){cout << "Invalid Index";}
	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 gridfunction[i][j]=factor*sourcegridfunction.getGridfunction()[i][j];
		 }
	 }
}

void Gridfunction::SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, Gridfunction& sourcegridfunction, MultiIndexType& offset){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>griddimension[0]){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>griddimension[1]){cout << "Invalid Index";}
	if (begin[0]+offset[0]<0){cout << "Invalid Index";}
	if (begin[0]+offset[0]>griddimension[0]){cout << "Invalid Index";}
	if (end[0]+offset[0]<0){cout << "Invalid Index";}
	if (end[0]+offset[0]>griddimension[0]){cout << "Invalid Index";}
	if (begin[1]+offset[1]<0){cout << "Invalid Index";}
	if (begin[1]+offset[1]>griddimension[1]){cout << "Invalid Index";}
	if (end[1]+offset[1]<0){cout << "Invalid Index";}
	if (end[1]+offset[1]>griddimension[1]){cout << "Invalid Index";}


	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 gridfunction[i][j]=factor*sourcegridfunction.getGridfunction()[i+offset[0]][j+offset[1]];
		 }
	 }
}

void Gridfunction::SetGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, Gridfunction& sourcegridfunction, MultiIndexType& offset, RealType constant){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>griddimension[0]){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>griddimension[1]){cout << "Invalid Index";}
	if (begin[0]+offset[0]<0){cout << "Invalid Index";}
	if (begin[0]+offset[0]>griddimension[0]){cout << "Invalid Index";}
	if (end[0]+offset[0]<0){cout << "Invalid Index";}
	if (end[0]+offset[0]>griddimension[0]){cout << "Invalid Index";}
	if (begin[1]+offset[1]<0){cout << "Invalid Index";}
	if (begin[1]+offset[1]>griddimension[1]){cout << "Invalid Index";}
	if (end[1]+offset[1]<0){cout << "Invalid Index";}
	if (end[1]+offset[1]>griddimension[1]){cout << "Invalid Index";}


	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 gridfunction[i][j]=factor*sourcegridfunction.getGridfunction()[i+offset[0]][j+offset[1]]+constant;
		 }
	 }
}

void Gridfunction::AddToGridFunction(const MultiIndexType& begin, const MultiIndexType& end, RealType factor, Gridfunction& sourcegridfunction){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>griddimension[0]){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>griddimension[1]){cout << "Invalid Index";}
	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 gridfunction[i][j]+=factor*sourcegridfunction.getGridfunction()[i][j];
		 }
	 }
}

RealType Gridfunction::MaxValueGridFunction(const MultiIndexType& begin, const MultiIndexType& end){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>griddimension[0]){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>griddimension[1]){cout << "Invalid Index";}
	RealType max = 0;
	for(int i=begin[0]; i<=begin[1]; i++){
	  for(int j=end[0]; j<=end[1]; j++ ){
		if (gridfunction[i][j]>max) max=gridfunction[i][j];
	  }
	}
	return max;
}

void Gridfunction::MultiplyGridFunctions(const MultiIndexType& begin, const MultiIndexType& end, Gridfunction& sourcegridfunction){
	if (begin[0]<0){cout << "Invalid Index";}
	if (end[0]>griddimension[0]){cout << "Invalid Index";}
	if (begin[1]<0){cout << "Invalid Index";}
	if (end[1]>griddimension[1]){cout << "Invalid Index";}
	for (int i=begin[0];i<=end[0];i++){
		 for (int j=begin[1];j<=end[1];j++){
			 gridfunction[i][j]*=sourcegridfunction.getGridfunction()[i][j];
		 }
	 }
}
void Gridfunction::Grid_Print(){
	for(int i=0;i<griddimension[0];i++){
		for(int j=0;j<griddimension[0];j++){
			cout << gridfunction[i][j] << " ";
		}
		cout << "\n";
	}
}
