#include<iostream>
#include<stdlib.h>

int main()
{
	int n,source,i,j,permanent_pts =1;
	scanf("%d",&n);
	scanf("%d",&source);
	
	int **matrix = (int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	matrix[i] = (int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	scanf("%d",&matrix[i][j]);
	if(i!=j && matrix[i][j]==0)
	matrix[i][j]=1000;
    }
	int *shortcut = (int*)malloc(n*sizeof(int));
	
	int S[n];
	for(i=0;i<n;i++)
	{
		shortcut[i] = matrix[source][i];
		
		if(i==source)
		S[i]=1;
		else
		S[i]=0;
	}
	
	
	int min,index;
	while(permanent_pts<n)
	{
		min = 1000;
		for(i=0;i<n;i++)
		{
		   if(S[i]==0)
		   {
		   	 if(shortcut[i]<min)
		   	 {
		   	   min = shortcut[i];
			   index =i;	  	
			 }
		   }	
		}
		S[index]=1;
		permanent_pts++;
		for(i=0;i<n;i++)
		{
			if(S[i]==0)
			{
				if(matrix[index][i]+shortcut[index]<shortcut[i])
				{
					shortcut[i] = matrix[index][i]+shortcut[index];
				}
			}
		}
	}
	free(matrix);
	for(i=0;i<n;i++)
	printf("%d:%d\n",i,shortcut[i]);
	free(shortcut);	
}

