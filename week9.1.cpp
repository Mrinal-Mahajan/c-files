#include<iostream>
#include<stdlib.h>

 
 int articulation(int x , int matrix[9][9])
 {
 	int i,flag=0,sum,j;
 	
 	for(i=0;i<9;i++)
 	{
 		matrix[x][i] = 0;
 		matrix[i][x] = 0;
	 }
	 for(i=0;i<9;i++)
	 {
	 	flag =0;
	 	sum =0;
	 	if(i!=x)
	 	{
	 		for(j=0;j<9;j++)
	 		sum+=matrix[i][j];
	 		
	 		if(sum == 0)
	 		{
	 			flag =1;
	 			break;
			 }
		 }
		 
	 }
	 return flag;
	 
 }
 
 int main()
 {
 	
 	int matrix[9][9] = 
	{{0,0,1,1,1,0,0,0,0},
 	 {0,0,1,0,1,0,0,1,1},
 	 {1,1,0,0,0,0,0,0,0},
 	 {1,0,0,0,1,1,0,0,0},
 	 {1,1,0,1,0,0,0,0,0},
 	 {0,0,0,1,0,0,1,0,0},
 	 {0,0,0,0,0,1,0,0,0},
     {0,1,0,0,0,0,0,0,0},
 	 {0,1,0,0,0,0,0,0,0},
                     };
 	int x;
 	scanf("%d",&x);
 	printf("%s",articulation(x,matrix) ? "Yes":"No");
 }
