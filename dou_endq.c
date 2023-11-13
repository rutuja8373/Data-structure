#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue
{
   int data[MAX];
   int rear,front;
}q;
void init()
{
   q.rear=q.front=-1;
}
int isfull()
{
   if((q.front==0&&q.rear==MAX-1)||(q.front==q.rear+1))
   	return 1;
   else
   	return 0;
}
int isempty()
{
   if(q.front==-1)
   	return 1;
   else
   	return 0;
}
int insert_rear(int num)
{
   if(isfull())
   	printf("\nOverflow");
   else
   {
      if(q.front==-1)
      {
         q.front=0;
      }
      q.rear=(q.rear+1)%MAX;
      q.data[q.rear]=num;
      printf("\nInsert succ");
   }
}
int insert_front(int num)
{
   if(isfull())
   	printf("\nOverflow");
   else
   {
       if(q.front==0)
       {
          q.rear=MAX-1;
       }
       q.front=q.front-1;
       q.data[q.front]=num;
       printf("\nInsert succ");
   }
}
int delete_front()
{
   int val;
   if(isempty())
  	printf("\nUnderflow");
    else
    {
       val=q.data[q.front];
       if(q.front==q.rear)
       {
          init();
       }
       q.front=(q.front+1)%MAX;
       return val;
    }
}
int delete_rear()
{
   int val;
   if(isempty())
  	printf("\nUnderflow");
    else
    {
        val=q.data[q.rear];
        q.rear=q.rear-1;
        return val;
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
int main()
{
   int ch,num;
  init();
  do{
    printf("\n1-insert rear\n2-insert front\n3-delete rear\n4-delete front\n5-display");
    printf("\nEnter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter number:");
    	     scanf("%d",&num);
    	     insert_rear(num);
    	     break;
      case 2:printf("\nEnter number:");
    	     scanf("%d",&num);
    	     insert_front(num);
    	     break;
      case 3:printf("\ndeleted value=%d",delete_rear());
      	     break;
      case 4:printf("\ndeleted value=%d",delete_front());
      	     break;
      case 5:display();
    	     break;
    }
  }while(ch<6);
}
