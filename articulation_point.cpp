#include<iostream>
#include<stdlib.h>
#include<stdbool.h>


struct vertex
{
	int disc,low,parent,children;
	bool visited,ap;
};
typedef struct vertex node;
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}

void DFS(node graph[],int matrix[9][9],int n)
{
	static int time=0;
	int i;
    graph[n].visited = true;
    graph[n].disc = time+1;
    graph[n].low = time+1;
    time++;
	for(i=0;i<9;i++)
	{
		if(matrix[n][i]==1)
		{
			if (!graph[i].visited)
			{
				graph[n].children++;
				graph[i].parent = n;
				DFS(graph,matrix,i);
				graph[n].low = min(graph[n].low,graph[i].low);
				
				if(graph[n].parent == -1 && graph[n].children>1)
				graph[n].ap = true;
				
				if(graph[n].parent!= -1 && graph[n].disc <= graph[i].low)
				graph[n].ap = true;
			}
			
			else if(graph[n].parent != i)
			graph[n].low = min(graph[n].low,graph[i].disc);
		}
	}	
}

 void analyse(node graph[],int matrix[9][9])
 {
   int i;
   for(i=0;i<9;i++)
   if(!graph[i].visited)
   DFS(graph,matrix,i);	
 }
 
 int articulation(int x , int matrix[9][9])
 {
   node graph[9];
   int i;
   for(i=0;i<9;i++)
   {
   	graph[i].parent = -1;
   	graph[i].children =0;
   	graph[i].visited = false;
   	graph[i].ap=false;
	   }	
   analyse(graph,matrix);
   if(graph[x].ap==true)
   return 1;
   else
   return 0;
 }
 
 int main()
 {
 	
 	int matrix[9][9] = {{0,0,1,1,1,0,0,0,0},
 	 {0,0,1,0,1,0,0,1,1},
 	 {1,1,0,0,0,0,0,0,0},
 	 {1,0,0,0,1,1,0,0,0},
 	 {1,1,0,1,0,0,0,0,0},
 	 {0,0,0,1,0,0,1,0,0},
 	 {0,0,0,0,0,1,0,0,0},
     {0,1,0,0,0,0,0,0,0},
 	 {0,1,0,0,0,0,0,0,0},
                     };
 	int x;
 	scanf("%d",&x);
 	printf("%s",articulation(x,matrix) ? "Yes":"No");
 }
