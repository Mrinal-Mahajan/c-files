#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctime>
using namespace std;
class vertex
{
	friend class queue;
	private:
		int index;
		int colour;
		vertex *next;
	public:
		vertex(int n)
		{
			index =n;
			colour =-1;
			next = NULL;
		};
		void setvalue(int n)
		{
			index =n;
			colour = -1;
			next = NULL;
		}
		void change(int n)
		{
			colour = n;
		};
		int return_color()
		{
			return colour;
		};
		int return_index()
		{
		   return index;	
		};
};
class queue
{
	vertex *first;
	public:
		queue()
		{
			first = NULL;
		};
		void push(vertex *insert)
		{
			if(first==NULL)
			first = insert;
			else
			{
				vertex *temp=first;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next = insert;
			}
		};
		int top()
		{
			return first->index;
		};
		void pop()
		{
			first = first->next;
		};
		
		bool isempty()
		{
			if(first==NULL)
			return true;
			else
			return false;
		}
};

bool is_bipartite(int **matrix,int v)
{
    vertex *nodes,*temp;
	nodes = (vertex*)malloc(v*sizeof(vertex));
	int i;
	for(i=0;i<v;i++)
	{
	  	nodes[i].setvalue(i);
	}  
	nodes[0].change(1);
	queue  list;
	list.push(&nodes[0]);
	int x,y;
	while(!list.isempty())
	{
		x = list.top();
		list.pop();
		for(y=0;y<v;y++)
		{
			if(matrix[x][y]==1)
			{
				if(nodes[y].return_color()==-1)
				{
					nodes[y].change(1-nodes[x].return_color());
					list.push(&nodes[y]);
				}
				else if(nodes[y].return_color()==nodes[x].return_color())
				return false;
			}
		}
	}
	return true;
};
int main()
{
	int v,e;
	scanf("%d %d",&v,&e);
	int **matrix,i,j,v1,v2;
	matrix = (int**)malloc(v*sizeof(int*));
	for(i=0;i<v;i++)
	matrix[i] = (int*)malloc(v*sizeof(int));
	for(i=0;i<v;i++)
	for(j=0;j<v;j++)
	matrix[i][j]=0;
	for(i=0;i<e;i++)
	{
		scanf("%d %d",&v1,&v2);
		matrix[v1][v2]=1;
		matrix[v2][v1]=1;
	}
	clock_t begin= clock();
	if(!is_bipartite(matrix,v))
	printf("No\n");
	else
	printf("Yes\n");
	clock_t end=clock();
	cout<<endl;
	double ans=(double)(end-begin)/CLOCKS_PER_SEC;
	cout<<ans<<endl;
}
