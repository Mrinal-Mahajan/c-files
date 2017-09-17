#include<bits/stdc++.h>
using namespace std;
int main()
{
	string code,attempt;
	int n,i,j,k,*correct,*pos_correct;
	cin>>code;
	scanf("%d",&n);
	correct = (int*)malloc(n*sizeof(int));
	pos_correct = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		correct[i]=0;
		pos_correct[i]=0;
	}
	for(i=0;i<n;i++)
	{
		cin>>attempt;
		for(j=0;j<code.size();j++)
		{
			if(code[j]==attempt[j])
			pos_correct[i]++;
		}
		for(j=0;j<code.size();j++)
		{
			for(k=0;k<attempt.size();k++)
			if(code[j]==attempt[k])
			correct[i]++;
		}
	}
	for(i=0;i<n;i++)
	printf("%d %d\n",pos_correct[i],correct[i]-pos_correct[i]);
}
