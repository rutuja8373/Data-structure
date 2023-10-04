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
char pop()
{
	char val;
	if(isempty())
	{
		printf("stack is empty dont pop..");
		return 0;
		
	}
	else
	{
		val=s.data[s.top];
		s.top--;
		return val;
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
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]!=pop())
			break;
	}
	if(isempty())
		printf("\nstring is palindrome..");
	else
		printf("\nstring is not palindrome..");
}
