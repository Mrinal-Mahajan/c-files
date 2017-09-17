#include<iostream>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node pair;
class Stack
{
	pair *first;
	int size;
	public:
	
		Stack(int a)
		{
			first = NULL;
			size =a;
		};
		
		int top()
	{
		if(first == NULL)
		return -1;
		else
		return first->data;
	};
		
		void push(int number)
	   {
		pair *temp;	
		temp = new pair;
		temp->data = number;
		temp->next = NULL;

         if(first != NULL)
         temp->next = first;
         
        first = temp;
	   };
	   
	   void print()
	{
		pair *ptr = first;
		int array[size],i=0;
		while(ptr!=NULL)
		{
			array[i] = ptr->data;
			i++;
			ptr=ptr->next;
		}
		for(i=0;i<size;i++)
		printf("%d ",array[i]);
	};
	
	
	   void returnNLN(Stack Input)
	   {
	   	pair *temp;
	   	pair *curr ;
	   
	   for(curr=Input.first;curr!=NULL;curr=curr->next){
	   	//temp=curr->next;
	   	for(temp=curr->next;temp!=NULL;temp=temp->next){
	   		if(temp->data > curr->data)
	   			break;
		   }
		   	if(temp == NULL)
		     {
		     	this->push(-1);
		     		//printf("%d ",this->top());
			 }
		    else
		     {
		     this->push(temp->data);
		     	//printf("%d ",this->top());
		    }
		     
		    //   curr = curr->next;
		   	
	   }
	   /*
	   	while(curr != NULL)
	   	{
	   	temp = curr->next;
	   	while(temp->data <= curr->data && temp != NULL)
	    temp=temp->next;
	       
	     if(temp == NULL)
	     {
	     	this->push(-1);
	     		printf("%d ",this->top());
		 }
	     
	     else
	     {
	     this->push(temp->data);
	     	printf("%d ",this->top());
	     }
	     */
	     //  curr = curr->next;
	    //}
			//this->print();
	   };	   
};

int main()
{
	int n,i,number;
	scanf("%d",&n);
	Stack array(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&number);
		array.push(number);
	}
	//array.print();
	//array.top();
	Stack answer(n);
	answer.returnNLN(array);
	answer.print();
	return 0;
}
