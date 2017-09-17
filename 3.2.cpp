#include<stdio.h>
int factorial(int n)
{
	if(n==1)
	return 1;
	else
	return n*factorial(n-1);
}
int permutation(int a,int b)
{
	return factorial(a)/factorial(a-b);
}
int commutation(int a,int b)
{
	return permutation(a,b)/factorial(b);
}
int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	printf("%d",commutation(a,b)-permutation(c,d));
}
