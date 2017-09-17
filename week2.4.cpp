#include<stdio.h>
#include<string.h>
int main()
{
	char string[100];
	scanf("%s",&string);
	int i,n=strlen(string),j,k;
	for(i=0;i<n;i++)
	{
		if(string[i]>='a' && string[i]<='z')
		{
			k=0;
			for(j=0;j<i;j++)
			{
				if(string[j]=='(')
				k++;
				if(string[j]==')')
				k--;
			}
			printf("%d",k);
		}
	}
	
}
