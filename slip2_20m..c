#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack
{
	int data[MAX];
	int top;
}s1,s2;
void init(struct stack *s)
{
	s->top=-1;
}
int isfull(struct stack *s)
{
	if(s->top==MAX-1)
		return 1;
	else
		return 0;
}
int isempty(struct stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
void push(struct stack *s,int num)
{
	if(isfull(s))
		printf("\nStack is full dont push..");
	else
	{
		s->top++;
		s->data[s->top]=num;
	}
}
int pop(struct stack *s)
{
	int val;
	if(isempty(s))
		printf("\nStack is empty dont pop..");
	else
	{
		val=s->data[s->top];
		s->top--;
		return val;
	}
}
void display(struct stack *s)
{
	int i;
	for(i=s->top;i>=0;i--)
	{
		printf("%d\t",s->data[i]);
	}
}
int main()
{
	int n,i,num;
	printf("\nEnter limit:");
	scanf("%d",&n);
	init(&s1);
	init(&s2);
	for(i=0;i<n;i++)
	{
		printf("\nEnter value of 1st:");
		scanf("%d",&num);
		push(&s1,num);
	}
	for(i=0;i<n;i++)
	{
		printf("\nEnter value 2nd :");
		scanf("%d",&num);
		push(&s2,num);
	}
	printf("\nFirst Stack value:");
	display(&s1);
	printf("\nSecond Stack value:");
	display(&s2);
	while(!isempty(&s1)&&!isempty(&s2))
	{
		if(pop(&s1)!=pop(&s2))
			break;
	}
	if(isempty(&s1)&&isempty(&s2))
		printf("\nStack are identical..");
	else
		printf("\nStack are not identical..");
}
