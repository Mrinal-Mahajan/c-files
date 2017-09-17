#include<bits/stdc++.h>
using namespace std;
#define int_size 40           //no. range in 10^12
class node
{
	friend class tree;
	private:
	long int value;
	int repeat;                    //no. of times value will be repeated in tree
	node *lchild,*rchild;
	public:
		node()
		{
			value = 0;
			repeat =0;
			lchild=rchild=NULL;
		}
		void increase_repeat()
		{
			repeat++;
		}
		void decrease_repeat()
		{
			repeat--;
		}
};
class tree
{
	node *root;
	public:
		tree()
		{
			root = new node();
		}
		void insert(long int n)           //insert a no. in tree
		{
			node *temp = root;
			int i;
			bool var;
			for(i = int_size - 1; i >= 0; i--)
			{
				var = n & (1<<i);
				if(var)
				{
					if(temp->rchild==NULL)
					{
						temp->rchild = new node();
					}
					temp = temp->rchild;
				}
				else
				{
					if(temp->lchild==NULL)
					{
						temp->lchild = new node();
					}
					temp = temp->lchild;
				}
			}
			if(temp->value != 0)                      //tree already contains value
			temp->increase_repeat();
			
			else
			temp->value =n;
		}
	long int max(long int n)                       //find maximum xor for a given no. with numbers in tree
	{
	   node *temp = root;
			int i;
			bool var;
			for(i=int_size-1; i>=0; i--)
			{
				var = n & (1<<i);
				if(var)
				{
					if(temp->lchild!=NULL)
						temp = temp->lchild;
					
					else if(temp->rchild!=NULL)
						temp = temp->rchild;
					
				}
				else
				{
					if(temp->rchild!=NULL)
						temp = temp->rchild;
				
					else if(temp->lchild!=NULL)
					temp = temp->lchild;
				}
			}
			if(temp->value ^ n >n)
			return temp->value ^ n;                //temp->value is no. for which max xor obtained with n
			else
			return n;                            
	}	
	void remove(long int n)                       //remove a number from tree
	{
		node *temp = root,*identifier = root;         //identifier is node after which subtree not have more than 1 child
			int i;                                    //for any node
			bool var,is_left,is_right;
			for(i=int_size-1;i>=0;i--)
			{
				var = n & (1<<i);
				if(var)
				{
					if(temp->rchild!=NULL)
					{
						temp = temp->rchild;
						if(temp->rchild!=NULL && temp->lchild != NULL)
						{
							identifier = temp;
						}
						else
						{
						 if(temp->rchild!=NULL)
						 {
						 	is_right = true;
						 	is_left = false;
						 }
						 else if(temp->lchild!=NULL)
						 {
						 	is_right = false;
						 	is_left = true;
						 }
						}
				    }
					else if(temp->lchild!=NULL)
					{
						temp = temp->lchild;
						if(temp->rchild!=NULL && temp->lchild != NULL)
						{
							identifier = temp;
						}
						else
						{
							if(temp->rchild!=NULL)
						 {
						 	is_right = true;
						 	is_left = false;
						 }
						 else if(temp->lchild!=NULL)
						 {
						 	is_right = false;
						 	is_left = true;
						 }
						}
					}
				}
				else
				{
					if(temp->lchild!=NULL)
					{
						temp = temp->lchild;
						if(temp->rchild!=NULL && temp->lchild != NULL)
						{
							identifier = temp;
						}
						else
						{
						 is_right = false;
						 is_left = true;	
						}
				    }
					else if(temp->rchild!=NULL)
					{
					temp = temp->rchild;
					if(temp->rchild!=NULL && temp->lchild != NULL)
						{
							identifier = temp;
						}
						else
						{
						 is_right = true;
						 is_left = false;	
						}
				    }
				}
		 }
			if(temp->repeat>1)                             //more than 1 repetition
			temp->decrease_repeat();
			else
			{
				if(is_right)
				identifier->rchild=NULL;
				else if(is_left)
				identifier->lchild=NULL;                  //remove the no. from tree
			}
	}
};

long int max_Xor(long int array[],int n)
{
  long int suffix[n],prefix[n],ans,fake;      //form an array of all prefixes and suffixes
  int i;
  prefix[0]=array[0];
  suffix[n-1]=array[n-1];
  tree *mango;
  mango = new tree();
  mango->insert(suffix[n-1]);
  for(i=1;i<n;i++)
  {
     prefix[i]=prefix[i-1]^array[i];
	 suffix[n-1-i] = suffix[n-i] ^ array[n-1-i];
	 if(i!=n-1)
	 mango->insert(suffix[n-1-i]); 	             //except suffix[0] insert array suffix in tree 
  }
  	ans = suffix[0];
  	for(i=0;i<n;i++)
  	{
  		fake = mango->max(prefix[i]);
  		if(ans<fake)
  		ans = fake;
  		mango->remove(suffix[i+1]);              //to avoid clash in prefix and suffix
	  }
	return ans;
}

int main()
{
	int n;
	scanf("%d",&n);
	long int *array = new long int[n];
	long int i;
	for(i=0;i<n;i++)
	scanf("%ld",&array[i]);	
	printf("%ld\n",max_Xor(array,n));
}
