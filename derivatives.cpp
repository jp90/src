/* * derivatives.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: jan-philippwolf
 */
#include "derivatives.h"

Gridfunction UUx(const MultiIndexType& dimension,
		          Gridfunction& u,const RealType alpha,const PointType& h){

	MultiIndexType begin, end;

	begin[0]=1;
	     end[0]=dimension[0]-2;
	     begin[1]=1;
	     end[1]=dimension[1]-2;

 Gridfunction branch_1(dimension);
      Stencil stencil_1(3,h);
      stencil_1.setUUx_1Stencil();
      stencil_1.ApplyStencilOperator(begin,end,begin,end,u,branch_1);
      branch_1.MultiplyGridFunctions(begin,end,branch_1);

      Gridfunction branch_2(dimension);
      Stencil stencil_2(3,h);
      stencil_2.setUUx_2Stencil();
      stencil_2.ApplyStencilOperator(begin,end,begin,end,u,branch_2);
      branch_2.MultiplyGridFunctions(begin,end,branch_2);

      branch_1.AddToGridFunction(begin,end,-1.0,branch_2);
      branch_1.ScaleGridFunction(begin,end,1.0/h[0]);


      Gridfunction branch_3(dimension);
      Stencil stencil_3(3,h);
      stencil_3.setUUx_3Stencil();
      stencil_3.ApplyStencilOperator(begin,end,begin,end,u,branch_3);
      branch_3.MultiplyGridFunctions(begin,end,branch_3);


      Gridfunction branch_4(dimension);
      Stencil stencil_4(3,h);
      stencil_4.setUUx_4Stencil();
      stencil_4.ApplyStencilOperator(begin,end,begin,end,u,branch_4);
      branch_4.MultiplyGridFunctions(begin,end,branch_4);

      branch_3.MultiplyGridFunctions(begin,end,branch_4);



      Gridfunction branch_5(dimension);
      Stencil stencil_5(3,h);
      stencil_5.setUUx_5Stencil();
      stencil_5.ApplyStencilOperator(begin,end,begin,end,u,branch_5);
      branch_5.MultiplyGridFunctions(begin,end,branch_5);

      Gridfunction branch_6(dimension);
      Stencil stencil_6(3,h);
      stencil_6.setUUx_6Stencil();
      stencil_6.ApplyStencilOperator(begin,end,begin,end,u,branch_6);
      branch_6.MultiplyGridFunctions(begin,end,branch_6);

      branch_5.MultiplyGridFunctions(begin,end,branch_6);

      branch_3.AddToGridFunction(begin,end,-1.0,branch_5);

      branch_3.ScaleGridFunction(begin,end,alpha/h[0]);

      branch_1.AddToGridFunction(begin,end,1.0,branch_3);

      return branch_1;

      }

Gridfunction VVy(const MultiIndexType& dimension,
		          Gridfunction& v,const RealType alpha,const PointType& h){

	MultiIndexType begin, end;

	begin[0]=1;
	end[0]=dimension[0]-2;
	begin[1]=1;
	end[1]=dimension[1]-2;

	Gridfunction branch_1(dimension);
      Stencil stencil_1(3,h);
      stencil_1.setVVy_1Stencil();
      stencil_1.ApplyStencilOperator(begin,end,begin,end,v,branch_1);
      branch_1.MultiplyGridFunctions(begin,end,branch_1);

      Gridfunction branch_2(dimension);
      Stencil stencil_2(3,h);
      stencil_2.setVVy_2Stencil();
      stencil_2.ApplyStencilOperator(begin,end,begin,end,v,branch_2);
      branch_2.MultiplyGridFunctions(begin,end,branch_2);

      branch_1.AddToGridFunction(begin,end,-1.0,branch_2);
      branch_1.ScaleGridFunction(begin,end,1.0/h[0]);


      Gridfunction branch_3(dimension);
      Stencil stencil_3(3,h);
      stencil_3.setUUx_3Stencil();
      stencil_3.ApplyStencilOperator(begin,end,begin,end,v,branch_3);
      branch_3.MultiplyGridFunctions(begin,end,branch_3);


      Gridfunction branch_4(dimension);
      Stencil stencil_4(3,h);
      stencil_4.setUUx_4Stencil();
      stencil_4.ApplyStencilOperator(begin,end,begin,end,v,branch_4);
      branch_4.MultiplyGridFunctions(begin,end,branch_4);

      branch_3.MultiplyGridFunctions(begin,end,branch_4);



      Gridfunction branch_5(dimension);
      Stencil stencil_5(3,h);
      stencil_5.setUUx_5Stencil();
      stencil_5.ApplyStencilOperator(begin,end,begin,end,v,branch_5);
      branch_5.MultiplyGridFunctions(begin,end,branch_5);

      Gridfunction branch_6(dimension);
      Stencil stencil_6(3,h);
      stencil_6.setUUx_6Stencil();
      stencil_6.ApplyStencilOperator(begin,end,begin,end,v,branch_6);
      branch_6.MultiplyGridFunctions(begin,end,branch_6);

      branch_5.MultiplyGridFunctions(begin,end,branch_6);

      branch_3.AddToGridFunction(begin,end,-1.0,branch_5);

      branch_3.ScaleGridFunction(begin,end,alpha/h[0]);

      branch_1.AddToGridFunction(begin,end,1.0,branch_3);

      return branch_1;

      }



