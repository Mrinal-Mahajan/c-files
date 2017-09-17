#include<stdio.h>
int absolute(int n)
{
	if(n<0)
	return -1*n;
	else
	return n;
}
int main()
{
	int n,num,i,j,index,min;
	scanf("%d %d",&n,&num);
	int array[n],diff[n];
	for(i=0;i<n;i++)
	{
	scanf("%d",&array[i]);
	diff[i] = absolute(array[i]-num);
    }
    for(j=1;j<=5;j++)
    {
    	min = 20000;
    	for(i=0;i<n;i++)
    	{
    		if(diff[i]<=min)
    		{
    			min = diff[i];
    			index =i;
			}
		}
		printf("%d ",array[index]);
		diff[index]= 20001;
	}
	
	
}
