#include<stdio.h>

void quicksort(int array[],int left,int right)
{
   int i=left,j=right,x=array[(left+right)/2],temp;
   do
   {
   	while(array[i]<x)
   	i++;
   	while(array[j]>x)
   	j--;
   	if(i<=j)
   	{
   		temp=array[i];
   		array[i]=array[j];
   		array[j]=temp;
   		i++;
   		j--;
	   }
   }
   while(i<=j);
   if(left<j)
   quicksort(array,left,j);
   if(right>i)
   quicksort(array,i,right);
}

int main()
{
	int n,m,i,l,r,triplets,sum;
	scanf("%d %d",&n,&m);
	int array[n];
	for(i=0;i<n;i++)
	scanf("%d",&array[i]);
	quicksort(array,0,n-1);
	
	triplets =0;
	for(i=0;i<n-2;i++)
	{
	  l=i+1;
	  r=n-1;
	  while(l<r)
	  {
	  	sum = array[i]+array[l]+array[r];
	  	if(sum==m)
	  	{
		  triplets++;
		  break;
	    }
	  	else if(sum<m)
	  	l++;
	  	else
	  	r--;
	  }
	}
	printf("%d",triplets);
	
}
