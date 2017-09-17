#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

int verified(int *row, int *col,int n)
{
	int i,flag=1;
	for(i=0;i<n-1;i++)
	if(col[i]!=row[i+1])
	{
		flag=0;
		break;
	}
	return flag;
}
int min_operation(int p[], int n)
{
    int m[n][n]; 
    int i, j, k, L, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;
     for (L=2; L<n; L++)   
    {
        for (i=1; i<=n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    return m[1][n-1];
    
}

int min_product(int *row,int *col,int n)
{
	if(verified(row,col,n)==0)
	{
		printf("Error\n");
		return 0;
	}
	else
	{
	   int *array = (int*)malloc((n+1)*sizeof(int)),i;
	   array[0]=row[0];
	   for(i=1;i<n+1;i++)
	   array[i]=col[i-1];
	   return min_operation(array,n+1);	
	}
}
int main()
{
	int no_of_mat,i;
	scanf("%d",&no_of_mat);
	int *row = (int*)malloc(no_of_mat*sizeof(int));
	int *col = (int*)malloc(no_of_mat*sizeof(int));
	for(i=0;i<no_of_mat;i++)
	scanf("%d %d",&row[i],&col[i]);
	printf("%d",min_product(row,col,no_of_mat));
	return 0;
}
