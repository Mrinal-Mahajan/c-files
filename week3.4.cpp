#include<stdio.h>
int power(int x,int y)
{
	if(y==0)
	return 1;
	if(y==1)
	return x;
	if(y%2==0)
	return power(x,y/2)*power(x,y/2);
	else
	return x*power(x,y/2)*power(x,y/2);
}
int main()
{
	int n,x;
	scanf("%d %d",&n,&x);
	int coeff[n+1],i,sum=0;
	for(i=n;i>=0;i--)
	{
	scanf("%d",&coeff[i]);
	sum+=coeff[i]*power(x,i);
    } 
    printf("%d",sum);
}
