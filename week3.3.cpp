#include<stdio.h>
int main()
{
 int T,array[10],i,j,k,min;
 scanf("%d",&T);
 int result[T];
 for(i=0;i<T;i++)
 {
 	for(j=0;j<10;j++)
 	scanf("%d",&array[j]);
 	for(k=1;k<=3;k++)
 	{
 		min=30;
 		for(j=0;j<10;j++)
 		{
 		  	if(array[j]<=min)
 		  	min = array[j];
		 }
		 if(k<=2)
		 for(j=0;j<10;j++)
		 {
		 	
		 	if(min==array[j])
		 	{
		 		array[j]=31;
		 		break;
			 }
		 }
		 else
		 for(j=0;j<10;j++)
		 {
		 	
		 	if(min==array[j])
		 	{
		 		result[i]=j+1;
		 		break;
			 }
		 }
		 
		 
		 
	 }
 }
             for(i=0;i<T;i++)
             printf("%d\n",result[i]);
}
