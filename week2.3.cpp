#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	int array[n],i,max=0,j,sum,k;
	for(i=0;i<n;i++)
	scanf("%d",& array[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			sum = array[i];
			for(k=1;k<=j;k++)
			sum+=array[i+k];
			
			if(sum>max)
		    max=sum;
		}
	}
	printf("%d",max);
	
}
