#include<iostream>
#include<math.h>

struct matrixtype
{
	int dim;
	int array[10][10];
};

class MatrixADT 
{
  private:
  struct matrixtype  result;
  
  public:
  void initializeresult(int dim)
  {
  	result.dim = dim;
  	int i,j;
  	for(i=0;i<dim;i++)
  	for(j=0;j<dim;j++)
  	result.array[i][j]=0;
  }	;
  
  void printresult(int dim)
  {
  	int i,j;
  	for(i=0;i<dim;i++)
  	{
	  
	for(j=0;j<dim;j++)
	printf("%d ",result.array[i][j]);
	
	printf("\n");
  }
  printf("Done");
  };
  struct matrixtype add(struct matrixtype M1,struct matrixtype M2)
  {
  	int i,j;
  	for(i=0;i<M1.dim;i++)
  	for(j=0;j<M1.dim;j++)
  	result.array[i][j]=M1.array[i][j]+M2.array[i][j];
  	
  	return result;
  };
  
  struct matrixtype subtract(struct matrixtype M1,struct matrixtype M2)
  {
  	int i,j;
  	for(i=0;i<M1.dim;i++)
  	for(j=0;j<M1.dim;j++)
  	result.array[i][j]=M1.array[i][j]-M2.array[i][j];
  	
  	return result;
  };
  
  struct matrixtype multiply(struct matrixtype M1,struct matrixtype M2)
  {
  	int i,j,k;
  	for(i=0;i<M1.dim;i++)
  	for(j=0;j<M1.dim;j++)
  	result.array[i][j]=0;
  	
  	for(i=0;i<M1.dim;i++)
  	{for(j=0;j<M1.dim;j++)
  	{
  		for(k=0;k<M1.dim;k++)
  		result.array[i][j]+=M1.array[i][k]*M2.array[k][j];
	  }
	  }
  	return result;
  };
  
};
int main()
{
	int n,i,j;
	char operation;
	scanf("%d %c",&n,&operation);
	
	MatrixADT  answer ;
	answer.initializeresult(n);
	
	struct matrixtype M1,M2;
	M1.dim=n;
	M2.dim=n;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&M1.array[i][j]);

	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&M2.array[i][j]);
	
	switch(operation)
	{
		case '+':
			answer.add(M1,M2);
			break;
		case '-':
			answer.subtract(M1,M2);
			break;
		case '*':
			answer.multiply(M1,M2);
			break;
	}
	answer.printresult(n);
}
