#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	struct node *next;
};
typedef struct node point;

class linked_list
{
	point *first;
	public:
		linked_list()
		{
			first=NULL;
		}
		void insert(int n)
		{
			if(first==NULL)
			{
				first = new point();
				first->x = n;
			}
			else
			{
				point *temp = first;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next = new point();
				temp->next->x = n;
			}
		}
		void print()
		{
			if(first!=NULL)
			{
				point *temp = first;
				while(temp!=NULL)
				{
					printf("%d ",temp->x);
					temp = temp->next;
				}
			}
		}
		void mid_reverse()
		{
			point *temp = first,*temp1;
			if(first!=NULL)
			{
			int size =1;			
			while(temp->next!=NULL)
			{
				temp = temp->next;
				size++;
			}
			int i = (size+size%2)/2,j=1;
			temp = first;
			while(j<i)
			{
				temp= temp->next;
				j++;
			}
			temp1 = temp->next;
			point *prev = temp1;
			point *current = temp1->next;
			point *next ;
			while(current!=NULL)
			{
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}
			temp->next = prev;
			temp1->next = NULL;
		   }
		}
};
int main()
{
    linked_list *array;
    array = new linked_list();
    int n,j=0;
    char c;
    do
    {
    	cin>>n;
    	array->insert(n);
	}
	while(cin.get()!='\n');
	array->print();
	printf("\n");
	array->mid_reverse();
	array->print();
	
}
