#include<stdio.h>
#define MAX 50
struct stack
{
	char data[MAX];
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
void push(char c)
{
	if(isfull())
	{
		printf("stack is full dont push..");
	}
	else
	{
		s.top++;
		s.data[s.top]=c;
		//printf("\npush successfuly!!");	
	}
}
void pop()
{
	char val;
	if(isempty())
	{
		printf("stack is empty dont pop..");
	}
	else
	{
		val=s.data[s.top];
		s.top--;
		printf("\npoped value=%c",val);
	}
}
void display()
{
	int i;
	for(i=s.top;i>=0;i--)
	{
		printf("%c\n",s.data[i]);
	}
}
int main()
{
	char s1[50];
	int i;
	init();
	printf("Enter string:");
	gets(s1);
	for(i=0;s1[i]!='\0';i++)
	{
		push(s1[i]);
	}
	printf("\nReverse string=\n");
	display();
}
