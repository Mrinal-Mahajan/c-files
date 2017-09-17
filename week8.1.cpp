#include<iostream>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node listnode;

class LinkedList
{
	listnode *first;
	public:
		LinkedList()
		{
			first = NULL;
		};
		
		void insert(int num)
		{
			listnode *temp;
			temp = new listnode;
			temp->data = num;
			temp->next = NULL;
			
			if(first!=NULL)
			temp->next = first;
			
			first = temp;
			
		};
		
		listnode *returnfirst()
		{
			return first;
		};
		
		
};
int intersection(LinkedList *Input1,LinkedList *Input2)
		{
			listnode *temp1,*temp2;
			int sum =0;
			for(temp1 = Input1->returnfirst();temp1 != NULL;temp1 = temp1->next)
			{
				for(temp2 = Input2->returnfirst();temp2 != NULL;temp2 = temp2->next)
				if(temp1->data == temp2->data)
				{
					sum+=temp1->data;
					break;
				}
			}
			return sum;
		};
		int Union(LinkedList *Input1,LinkedList *Input2)
		{
			listnode *temp1,*temp2;
			int flag,sum=0;
			for(temp1 = Input1->returnfirst();temp1 != NULL;temp1 = temp1->next)
			{
				flag = 0;
				for(temp2 = Input2->returnfirst();temp2 != NULL;temp2 = temp2->next)
				if(temp1->data == temp2->data)
				{
					flag =1;
					break;
				}
				if(flag == 0)
				sum+=temp1->data;
			}
			
			for(temp1 = Input2->returnfirst();temp1 != NULL;temp1 = temp1->next)
			{
				flag = 0;
				for(temp2 = Input1->returnfirst();temp2 != NULL;temp2 = temp2->next)
				if(temp1->data == temp2->data)
				{
					flag =1;
					break;
				}
				if(flag == 0)
				sum+=temp1->data;
			}
			return sum+intersection(Input1,Input2);
		};
int main()
{
	int n,i,num;
	scanf("%d",&n);
	LinkedList  *List1;
	List1 = new LinkedList;
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		List1->insert(num);
	}
	scanf("%d",&n);
	LinkedList  *List2;
	List2 = new LinkedList;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		List2->insert(num);
	}
	int ans = Union(List1,List2);
	printf("U%d\n",ans);
	ans = intersection(List1,List2);
	printf("I%d\n",ans);
	return 0;
}
