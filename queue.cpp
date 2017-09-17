#include<iostream>
#include<stdlib.h>


class queue
{
	int *arr;
	int front,rear;
	int max;
	
	public:
		queue(int size)
		{
			front = rear = -1;
			arr = new int [size];
			for(int i=0;i<size;i++)
			arr[i]=0;
			max = size;
		};
		void insert(int number)
		{
			if((rear+1)%max == front)
			printf("It's full man\n'");
		    
		    else
		    {
			rear = (rear+1)%max;
			arr[rear] = number;
			if(front==-1)
			front = 0;
		    }
		};
		int pop()
		{
			int data = arr[front];
			arr[front] = 0;
			front = (front+1)%max;
			return data;
		};
		void display()
		{
			int i;
			for(i=0;i<max;i++)
			printf("%d ",arr[i]);
		}
}; 

int main()
{
	int size;
	scanf("%d",&size);
	queue This_queue(size);
	int n,i=0;
	do
	{
		scanf("%d",&n);
		This_queue.insert(n);
		i++;
	}while(i<size && n!=0);
	This_queue.display();
	This_queue.insert(4);
	printf("%d\n",This_queue.pop());
	This_queue.insert(4);
	This_queue.display();
	printf("%d\n",This_queue.pop());
}
