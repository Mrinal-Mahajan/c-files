#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void quicksort(int *arrival,int *departure,int left,int right);

int platforms(int arrival[],int departure[], int n)
{
    if(n==1)
    return 1;
    else
    {
      quicksort(arrival,departure,0,n-1);
      int array[n],i,j,k=0,flag,index;
      array[k] = departure[k];
	  for(i=1;i<n;i++)
	  array[i] = 0;
	  for(i=1;i<n;i++)
	  {
	  	flag = 0;
	  	for(j=k;j>=0;j--)
	  	{
	  		if(arrival[i]>=array[j])
	  		{
	  			flag = 1;
	  			index = j;
	  			break;
			  }
		}
		if(flag == 0)
		{
			k++;
			array[k] = departure[i];
		}
		else
		array[index] = departure[i];
	  }	
	  return k+1;	
	}
	
};
void quicksort(int *arrival,int *departure,int left,int right)
{
	int x = arrival[(left+right)/2],i=left,j=right,temp;
	do{
		while(arrival[i]<x)
		i++;
		while(arrival[j]>x)
		j--;
		if(i<=j)
		{
		 temp = arrival[i];
		 arrival[i]=arrival[j];
		 arrival[j]=temp;
		 temp = departure[i];
		 departure[i]=departure[j];
		 departure[j]=temp;	
		 i++;
		 j--;
		}
	}while(i<=j);
	if(left<j)
	quicksort(arrival,departure,left,j);
	if(i<right)
	quicksort(arrival,departure,i,right);
};
int main()
{
	int n,num,i;
	scanf("%d",&n);
	int arrival[n],departure[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		arrival[i] = num/100*60 + num%100;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		departure[i] = num/100*60 + num%100;
	}
	printf("%d",platforms(arrival,departure,n));
}
