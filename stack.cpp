#include<iostream>
#include<math.h>

struct Cell
{
	int value;
	struct Cell *next;
};

class Stack
{
   struct Cell *first;
   
   public:
   Stack ()
   {
   	first = NULL;
	   };
	   	
	int top()
	{
		if(first == NULL)
		return -1;
		else
		return first->value;
	};
	
	int pop()
	{
		if(first == NULL)
		return -1;
		else
		{
			struct Cell *temp = first;
			first = first->next;
			return temp->value;
		}
	};
	void push(int number)
	{
		struct Cell *temp;	
		temp = new struct Cell;
		temp->value = number;
		temp->next = NULL;

         if(first != NULL)
         temp->next = first;
         
        first = temp;
	};
	
	int isempty()
	{
	  if(first == NULL)
	  return 1;
	  else
	  return 0;	
	};
	
	void print()
	{
		struct Cell *ptr = first;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->value);
			ptr=ptr->next;
		}
		printf("\nDone\n");
	};
		
};

int main()
{
	Stack The_list ;
	int n;
	do
	{
		scanf("%d",&n);
		The_list.push(n);
	}while(n != 0);
	The_list.print();
//	printf("%d ",The_list.pop());
//	printf("%d ",The_list.pop());
//	printf("%d ",The_list.pop());
//	printf("%d ",The_list.pop());
//	printf("%d ",The_list.top());
	
	The_list.print();
	int i=0;
	while(The_list.isempty() == 0)
	{
		i++;
		printf("%d %d\n",i,The_list.pop());
	}
}
