#include<stdio.h>
int factorial(int n)
{
	if(n==1 || n==0)
	return 1;
	
	else
	return n*factorial(n-1);
}

int permutation(int a, int b)
{
	if(a>=b)
	{
		return factorial(a)/factorial(a-b);
	}
	else
	return 0;
}

int combination(int c, int d)
{
	if(c>=d)
	return factorial(c)/(factorial(d)*factorial(c-d));
}
int main(){
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int ans = combination(a,b)-permutation(c,d);
	printf("%d",ans);	
}
