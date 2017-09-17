#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int ways(int n){
	if(n==1 || n==2)
	return n;
	else
	{
	  return ways(n-1)+ways(n-2);	
	};
};
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",ways(n));
}
