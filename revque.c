#include<stdio.h>
#define MAX 20
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
  if(q.rear==MAX-1)
  	return 1;
  else
  	return 0;
}
int isempty()
{
  if(q.front==-1&&q.rear<q.front)
  	return 1;
  else
   	return 0;
}
void insert(int num)
{
  if(isfull())
  	printf("\nQueue is overflow");
  else
  {
  if(q.front==-1)
  	q.front=0;
  	
    q.rear++;
    q.data[q.rear]=num;
  }
}
int deleteq()
{
 int num;
 if(isempty())
 	printf("\nQueue is underflow");
 else
 {
    num=q.data[q.front];
    q.front++;
    return num;
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
void reverse()
{
 int i;
  for(i=q.rear;i>=q.front;i--)
  {
    printf("%d\t",q.data[i]);
  }
}
int main()
{
  int ch,num;
  init();
  do{
    printf("\n1-insert\n2-delete\n3-display\n4-reverse");
    printf("\nEnter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter number:");
    	     scanf("%d",&num);
    	     insert(num);
    	     break;
      case 2:printf("\ndeleted value=%d",deleteq());
      	     break;
      case 3:display();
     	     break;
      case 4:reverse();
     	     break;
    }
  }while(ch<5);
}
