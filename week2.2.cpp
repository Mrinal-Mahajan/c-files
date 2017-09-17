#include<stdio.h>
#include<string.h>

int main()
{
	char s1[100],s2[100];
	scanf("%s %s",& s1,& s2);
	int len1 = strlen(s1),len2 = strlen(s2),k,i,n1,n2;
	if(len1==len2)
	{
		for(k=0;k<len1;k++)
		{
			n1=0;n2=0;
			for(i=0;i<len1;i++)
			{
				if(s1[k]==s1[i])
				n1++;
				if(s1[k]==s2[i])
				n2++;
			}
			if(n1==n2)
			continue;
			else
			break;
		}
		if(k==len1)
		printf("yes");
		else
		printf("no");
	}
	else
	printf("no");
}
