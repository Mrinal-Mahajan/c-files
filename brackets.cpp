#include<iostream>
#include<stdlib.h>

struct Brackets
{
	char a;
	struct Brackets *next; 
};
class String
{
	struct Brackets *first;
	public:
		Brackets()
		{
			first = NULL;
		};
        void push(char b)
		{
			struct Brackets *temp;
			temp = new struct Bracket;
			temp->a = b;
			temp->next = NULL;
			
			if(first!=NULL)
			temp->next = first;
			
			first = temp;
				};
		
		int check()
		{
			while(first->a != '(' || first->a != '{' || first->a != '[')
			{
				first = first->next;
			}
			
			
			while(current!= NULL)
			{
				switch(first->a)
				{
					case '(':
						if(current->a == ')')
						{
							
						}
				}
			}
				};		
};
