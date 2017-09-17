#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node  *next;
};

typedef struct node Node;

Node LoadNum();

void releasemem(Node head);

void printnum(Node head, int pos)
{
	int i=1;
	Node temp = head;
	while(i != pos)
	{
	  temp = temp->next;
	  if(temp == NULL)
	{
	printf("-1");
	return;
	}  i++;
	}
	printf("%d",temp->data);
	
}
int main()
{
  int i,T,pos;
  Node head;
  scanf("%d %d",&T);
  for(i=1;i<=T;i++)
  {
  	scanf("%d",&pos);
  	head = LoadNum();
  	printnum(head,pos);
  	printf("\n");
  	releasemem(head);
  }
  	
}

Node LoadNum()
{
  Node Head,curr;
  Head = (Node)malloc(sizeof(struct node));
  int a;
  scanf("%d",&a);
  Head.data=a;
  Head.next = NULL;
  curr = Head;
  scanf("%d",&a);
  while(a != -1)
  {
  	curr->next = (Node)malloc(sizeof(Node));
  	curr = curr->next;
  	curr.data = a;
  	curr.next = NULL;
  	scanf("%d",&a);
	  };
	return Head;	
}

void releasemem(Node head)
{
	Node temp;
	temp=head;
	while(temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	};
}

