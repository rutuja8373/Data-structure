#include<stdio.h>
#define MAX 5
struct queue
{
   int data[MAX];
   int rear,front;
}q;
void initq()
{
  q.front=q.rear=-1;
}
int isfull()
{
   if(q.rear==MAX-1)
   	return 1;
   else
   	return 0;
}
int isempty()
{
   if(q.front==-1||q.front>q.rear)
   	return 1;
   else
   	return 0;
}
void insertq(int num)
{
   if(isfull())
   	printf("\nqueue is overflow");
   else
   {
   if(q.front==-1)
   	q.front=0;
   	
      q.rear++;
      q.data[q.rear]=num;
      printf("\nInsert succ..");
   }
}
void deleteq()
{
   int num;
   if(isempty())
   	printf("\nqueue is underflow");
   else
   {
       num=q.data[q.front];
       q.front++;
       printf("\nDelete value=%d",num);
   }	
}
void display()
{
   int i;
   for(i=q.front;i<=q.rear;i++)
   {
      printf("%d\t",q.data[i]);
   }
}
void main()
{
  int ch,num;
  initq();
   do{
   	printf("\n1-insert\n2-delete\n3-display");
   	printf("\nEnter choice:");
   	scanf("%d",&ch);
   	switch(ch)
   	{
   	    case 1:printf("\nEnter num:");
   	    	   scanf("%d",&num);
   	    	   insertq(num);
   	    	   break;
   	    case 2:deleteq();
   	    	   break;
   	    case 3:display();
   	    	   break;
   	    default:printf("\nInvalid choice..");
   	    
   	}
   }while(ch<4);
}
