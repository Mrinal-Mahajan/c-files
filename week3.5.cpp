#include<stdio.h>
#include<string.h>
int main()
{
	char string[100];
	scanf("%s",&string);
	int i=0,j;
	while(string[i]!='\0')
	{
		i++;
	}

	for(j=0;j<i;j++)
	{
		if(string[j]==string[i-j-1])
	    {
		printf("%c",string[j]);
	    continue;
	    }
		else
		{
			if(j==0)
			{
				printf("0");
				break;
			}
			else
			break;
		}
	}
}
