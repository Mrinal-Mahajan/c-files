#include<stdio.h>

int main()
{
  int N,k,min,index,temp;
  scanf("%d %d",&N,&k);
  int array[N],i,j;
  for(i=0;i<N;i++)
  scanf("%d",& array[i]);
  
  for(i=0;i<k;i++)
  {
  	min = array[i+1];
  	index = i+1;
  	for(j=i+2;j<N;j++)
  	{
  	  if(array[j]<=min)
		{
			min = array[j];
			index =j;
			}	
	  }
	  temp = array[i];
	  array[i] = array[index];
	  array[index] = temp;
	  
	  }	
	for(i=0;i<N;i++)
	printf("%d ",array[i]);
}
