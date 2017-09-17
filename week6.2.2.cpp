#include<iostream>
#define Maxsize 100

class stack
{
	int array[Maxsize];
	int top;
	public:
		stack(){
			top = Maxsize;
		};
		
		void increasetop()
		{
		 top++;	
		};
		
		void push(int a)
		{
			if(top == 0)
			printf("\nSorry,stack is full\n");
			else
			{
				top--;
				array[top] = a;
			}
		};
		int pop()
		{
			if(top >= Maxsize)
			return 0;
			else
			{
				int temp = array[top];
				top++;
				return temp;
			}
		};
		int first()
		{
		  if(top >= Maxsize)
			return 0;
		  else
		  return array[top];	
		};
		
		Stack returnNLN(stack Input)
		{
		   int 	
		};
		void print()
		{
			int i;
			for(int i=Maxsize-1;i>=top;i--)
			printf("%d ",this->pop());
		};
};
int main()
{
	int n,i,num;
	stack Input;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		Input.push(num);
	}
	stack output;
	output.returnNLN(Input);
	output.print();
}

