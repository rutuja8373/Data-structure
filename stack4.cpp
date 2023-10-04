#include<stdio.h>
#define MAX 5
struct stack
{
	int data[MAX];
	int top;
}s;
void init()
{
	s.top=-1;
}
int isempty()
{
	if(s.top==-1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(s.top==MAX-1)
		return 1;
	else
		return 0;
}
void push(int num)
{
	if(isfull())
	{
		printf("stack is full dont push..");
	}
	else
	{
		s.top++;
		s.data[s.top]=num;
		printf("\npush successfuly!!");	
	}
}
void pop()
{
	int val;
	if(isempty())
	{
		printf("stack is empty dont pop..");
	}
	else
	{
		val=s.data[s.top];
		s.top--;
		printf("\npoped value=%d",val);
	}
}
void display()
{
	int i;
	for(i=s.top;i>0;i--)
	{
		printf("%d\n",s.data[i]);
	}
}
int main()
{
	int ch,num;
	do{
		printf("\n1-PUSH\n2-POP\n3-DISPLAY");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter num:");
				   scanf("%d",&num);
				   push(num);
				   break;
			case 2:pop();
			       break;
			case 3:display();
				   break;
			default:printf("\nInvalid choice..");
		}
	}while(ch<4);
}
