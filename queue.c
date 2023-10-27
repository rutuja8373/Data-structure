#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
}*rear,*front,*temp,*newnode;
void init()
{
   front=rear=NULL;
}
int isempty()
{
  if(front==NULL)
  	return 1;
  else
   	return 0;
}
void push(int num)
{
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=num;
  newnode->next=NULL;
  if(isempty())
  	front=rear=newnode;
  else
  {
     rear->next=newnode;
     rear=newnode;
     printf("\nInsert succ..");
  }
}
void deleteq()
{
  int num;
  if(isempty())
  	printf("\nQueue is underflow..");
  else
  {
  	num=front->data;
  	temp=front;
  	front=front->next;
  	free(temp);
  	printf("\nDeleted value=%d",num);
  }	
}
void disp()
{
   for(temp=front;temp!=NULL;temp=temp->next)
   {
     printf("%d\t",temp->data);
   }
}
void main()
{
  int ch,num;
  do{
    printf("\n1-push\n2-delete\n3-disp");
    printf("\nEnter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
       	case 1:printf("\nEnter num:");
       		scanf("%d",&num);
       		push(num);
       		break;
       case 2:deleteq();
       		break;
       case 3:disp();
       		break;
    }
  }while(ch<4);
}
