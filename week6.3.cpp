#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Tree;
class leaf {
	friend class Tree;
	
	private:
	int data;
	leaf *lchild;
	leaf *rchild;
	
	public:
		leaf()
		{
			data = -1;
			lchild=NULL;
			rchild=NULL;
		}
		leaf(int key)
		{
			data = key;
			lchild=NULL;
			rchild=NULL;
		}
		void setvalue(int key)
		{
			data = key;
		}
		void set_to_none()
		{
			data = -1;
			lchild = NULL;
			rchild = NULL;
		}
};

class Tree
{
	leaf *root;
	
	void insertion(int n, leaf *test)
		{
			if(test->data!=-1)
			{
					if(n<test->data){
						if(test->lchild != NULL)
						return	insertion(n,test->lchild);
						else
						{
						test->lchild = new leaf();
						return insertion(n,test->lchild);
					    }
				}
				else if(n>test->data){
					if(test->rchild != NULL)
					return insertion(n,test->rchild);
					else
					{
					 test->rchild = new leaf();
					 return insertion(n,test->rchild);	
					}	
				}
				
				else
				printf("\nThe value already exist\n");
				
			}
			else
			{
				test->setvalue(n);
			}
			
		};
		
	void removal(int key,leaf *test)
		{
			if(key < test->data)
			{
			 if(test->lchild!=NULL)
			removal(key,test->lchild);
			 else
			 {
			 printf("value not found\n");
			 return;
		     }
		    }
			else if(key >test->data)
			{
				if(test->rchild!=NULL)
			removal(key,test->rchild);
			 else
			 {
			 printf("value not found\n");
			 return;
		     }
			}
			
			else if(key==test->data)
			{
				leaf *prev = test;
				leaf *t = test->lchild;
				leaf *w = test->rchild;
				if(t!=NULL)
				{
					while(t->rchild != NULL)
					{
						prev =t;
						t = t->rchild;
					}
					test->data = t->data;
					delete(t);
				}
				else
				{
					if(w!=NULL)
					{
						test->data = w->data;
						test->lchild = w->lchild;
						test->rchild = w->rchild;
						delete(w);
					}
					else
					delete(test);
				}
			
//				if(test->lchild == NULL && test->rchild == NULL)
//				{
//				test = NULL;
//				delete test;
//		     	}
//				else if(test->lchild == NULL && test->rchild != NULL)
//				test = test->rchild;
//				
//				else if(test->lchild != NULL && test->rchild == NULL)
//				test = test->lchild;
//				
//				else
//				{
//					leaf *prev = test;
//					leaf *t = test->lchild;
//					while(t->rchild != NULL)
//					{
//						prev = t;
//						t = t->rchild;
//					}
//					test->data = t->data;
//					if(prev->lchild == t)
//					prev->lchild = t->lchild;
//					
//					else
//					prev->rchild = t->lchild;
//					delete t;
		//		}
			}
			
			else
			printf("\nvalue not found\n");
			
		};
		
		void postorder(leaf *test)
		{
			    if(test!=NULL)
			    {
				if(test->lchild!=NULL)
				postorder(test->lchild);
				
				if(test->rchild!=NULL)
				postorder(test->rchild);
				
				printf("%d\n",test->data);
			    }
			};
		
	public:
		Tree()
		{
			root = new leaf();
		};
		
		void insert(int key)
		{
			insertion(key,root);
		};
			
		
		
		
		void remove(int key)
		{
			removal(key,root);
		};
		
		
		void printtree()
		{
			if(root->data != -1){
				    if(root->lchild!=NULL)
					postorder(root->lchild);
					
					if(root->rchild!=NULL)
					postorder(root->rchild);
					
					printf("%d\n",root->data);
				}
			else
			printf("NULL");
           
			
						};	
};

int main()
{
	int n,t,i,num;
	scanf("%d",&n);
	Tree *mango;
	mango = new Tree;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		mango->insert(num);	
	}
	
	scanf("%d",&t);
	
	int to_operate;
	char operation;
	
	for(i=0;i<t;i++)
	{
		scanf("%d %c",&to_operate,&operation);
		if(operation == 'i')
		mango->insert(to_operate);
		else if(operation == 'd')
		mango->remove(to_operate);
		else
		printf("\ninvalid operation\n");
	}
	mango->printtree();
	
	return 0;
}
