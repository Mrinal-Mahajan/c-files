#include<bits/stdc++.h>
using namespace std;
int maximal(int array[],int n)
{
	static int index =0;
	array[0]=array[1]=(array[0]+array[1])/2;
	array[n-1-index]=-1;
	if(index==n-2)
	return array[0];
	else
	{
		index++;
		return maximal(array,n);
	} 
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int *array;
	array = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	scanf("%d",&array[i]);
	sort(array,array+n,greater<int>());
	printf("%d\n",maximal(array,n));
}
