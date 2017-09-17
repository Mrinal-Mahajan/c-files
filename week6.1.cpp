#include<iostream>
#include<math.h>

int isbalanced(int array[],int n)
{
	int i=0,j,k,temp =n;
	while(temp != 0)
	{
		temp =temp/2;
		i++;
	}
	if(i==1)
	return 1;
	else
	{
	  int lsum =0, rsum =0;
	  for(j=1;j<i;j++)
	  {
	    for(k=pow(2,j)-1;k<pow(2,j)+pow(2,j-1)-1;k++)
		lsum+=array[k];
		for(k=pow(2,j)+pow(2,j-1)-1;k<pow(2,j)*2-1;k++)
		rsum+=array[k];	
	  }	
	  if(lsum==rsum)
	  return 1;
	  else
	  return 0;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int array[n],i;
	for(i=0;i<n;i++)
	scanf("%d",&array[i]);
	int isbalance = isbalanced(array,n);
	if(isbalance == 1)
	printf("\nTree is balanced\n");
	else
	printf("\nTree is not balanced\n");
}
