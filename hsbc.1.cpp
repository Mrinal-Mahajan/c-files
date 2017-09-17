#include<bits/stdc++.h>
using namespace std;
void print_square(int n)
{
	int i,j;
	for(i=0;i<=n-(n+1)%2;i=i+2)
	{
		for(j=n*i+1;j<=n*(i+1);j++)
		{
			if(j==n*(i+1))
			printf("%d\n",j);
			else
			printf("%d*",j);
		}
	}
	
	for(i=n-n%2;i>1;i=i-2)
	{
		for(j=n*(i-1)+1;j<=n*i;j++)
		{
			if(j==n*i)
			printf("%d\n",j);
			else
			printf("%d*",j);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	print_square(n);
}
