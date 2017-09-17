#include<bits/stdc++.h>
using namespace std;
class node
{
	friend class tree;
	private:
	int value;
	node *lchild,*rchild;
	public:
		node()
		{
			value =-1;
			lchild=rchild=NULL;
		}
		void setvalue(int n1)
		{
			value =n1;
		}
};
class tree
{
	node *root;
	int height,siblings,index;    //height= depth of tree, siblings is no. of children at a bottomost level
	public:                       // index = no. of pixels needed to distinguish all numbers in tree
		tree()
		{
			root = new node();
			index =0;
			height =-1;
			siblings =1;
		}
		void insert(int array[])     //to insert an element it's subtree needs to be followed
		{
			int i=0;
			node *temp=root;
			while(i<height)
			{
				if(array[i]==0)
				{
					temp = temp->lchild;
					i++;
				}
				else
				{
					temp = temp->rchild;
					i++;
				}
			}
			if(array[i]==0)
			{
				if(temp->lchild == NULL)         //insert only if empty space
				{
				temp->lchild = new node();
				temp->lchild->setvalue(array[i]);
				siblings++;
			   }
			}
			else
			{
				if(temp->rchild == NULL)
				{
				temp->rchild = new node();
				temp->rchild->setvalue(array[i]);
				siblings++;
			    }
			}
		}
		void increase_height()              //height increased new elements will be inserted
		{
			height++;
			siblings =0;
		}
		void increase_index()              //if no. of siblings at given level greater than previous level
		{
			index++;                       
		}
		int return_index()
		{
			return index;
		}
		int return_siblings()
		{
			return siblings;
		}
};
int minimal_pixel(int **array,int n,int k)              
{
	tree *mango;
	mango = new tree();
	int i,j,prev;
	for(i=0;i<n;i++)
	{
		prev = mango->return_siblings();
		mango->increase_height();
		for(j=0;j<k;j++)
		  mango->insert(array[j]);
		
		if(prev<mango->return_siblings())         // at least one node with both children at previous level 
			mango->increase_index();                  
		
		if(mango->return_siblings()==k)          //all numbers distinguished
		   return mango->return_index();   
	}
}
int main()
{
	int n,m,k,**array,i,j,l;
	string input;
	scanf("%d %d %d",&n,&m,&k);
	array = (int**)malloc(k*sizeof(int*));
	for(i=0;i<k;i++)
	array[i]=(int*)malloc(n*m*sizeof(int));
	for(l=0;l<k;l++)                            //store matrix as binary number
	{
	  for(i=0;i<n;i++)
	  {
	  cin>>input;
	  for(j=0;j<m;j++)
	  array[l][i*m+j]=input[j]-'0';
     }
	}   
	printf("%d\n",minimal_pixel(array,n*m,k));
}
