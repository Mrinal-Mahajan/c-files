#include<iostream>
#include<stdlib.h>
int main()
{
	int n,i,j,permanent_pts =1,index1,index2,min;
	scanf("%d",&n);
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
//    int **shortcut = (int**)malloc(n*sizeof(int*));
//    for(i=0;i<n;i++)
//    shortcut[i] = (int*)malloc(3*sizeof(int));
    
    int *S = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
//    	shortcut[i][0] = i;
//    	shortcut[i][1] = 0;
//    	shortcut[i][2] = matrix[0][i];
    	if(i==0)
    	S[i]=1;
    	else
    	S[i]=0;
	}

    while(permanent_pts<n)
    {
      	min =1000;
      	for(i=0;i<n;i++)
      	{
      		if(S[i]==1)
      		for(j=0;j<n;j++)
      		{
      			if(S[j]==0)
      			if(min>matrix[i][j])
      			{
      			  min = matrix[i][j];
					index1 =i;
					index2 = j;	
				  }
			  }
		  }
		S[index2]=1;
		permanent_pts++;
		printf("%d-%d %d\n",index1,index2,matrix[index1][index2]);
	}
	free(matrix);
	free(S);
	return 0;
}
