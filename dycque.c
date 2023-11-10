#include<stdio.h>
#include<stdlib.h>
#define memory (struct node*)malloc(sizeof(struct node))
typedef struct node
{
   int data;
   struct node *next;
}node;
node *front,*rear;
void init()
{
   front=NULL;
   rear=NULL;
}
int isempty()
{
   if(front==NULL)
   	return 1;
   else
   	return 0;
}
node *insert(int num)
{node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if(front==NULL)
    {
       front=rear=newnode;
       newnode->next=front;
       return newnode;
    }
    else
    {
       rear->next=newnode;
       newnode->next=front;
       rear=newnode;
    }
    return front;
}
void deleteq()
{
  int num;
  node *temp,*temp1;
  if(isempty())
  	printf("\nQueue is underflow..");
  else
  {
      for(temp=front;temp->next!=front;temp=temp->next);
  	num=front->data;
  	temp1=front;
  	front=front->next;
  	temp->next=front;
  	free(temp1);
  	printf("\nDeleted value=%d",num);
  }	
}
void display()
{
   node *temp=front;
   do{
     printf("%d\t",temp->data);
     temp=temp->next;
   }while(temp!=front);
}
int main()
{
   int ch,num,val;
   init();
   do{
   printf("\n1-insert\n2-delete\n3-DISPLAY:");
   scanf("%d",&ch);
   switch(ch)
   {
   	case 1:printf("\nEnter value:");
   		scanf("%d",&num);
   		insert(num);
   		break;
   	case 2:deleteq();
   		//printf("\nDeleted value:%d",val);
   		break;
   	case 3:display();
   		break;
   }
   }while(ch<5);
}
