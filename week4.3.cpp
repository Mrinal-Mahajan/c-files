#include<stdio.h>

int polynomial(int array[],int k,int m)
{
	if(m==0)
	return array[0];
	
	else
	return array[m] + polynomial(array,k,m-1)*k;	
}

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int array[n+1],i;
	for(i=0;i<n+1;i++)
	scanf("%d",&array[i]);
	printf("%d " ,polynomial(array,k,m));
}
