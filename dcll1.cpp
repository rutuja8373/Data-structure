#include<stdio.h>
#include<stdlib.h>
#define memory (node*)malloc(sizeof(node));
typedef struct node
{
	int data;
	struct node *next,*prev;
}node;
node *create(node *list)
{
	node *temp,*newnode;
	int n,i;
	printf("\nEnter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=memory;
		printf("\nEnter value:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		if(list==NULL)
		{
			list=temp=newnode;
			list->next=newnode;
			newnode->prev=list;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			newnode->next=list;
			list->prev=newnode;
			temp=newnode;
		}
	}
	return list;
}
void display(node *list)
{
	node *temp=list;
	do{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp!=list);
}
int main()
{
	node *list=NULL;
	list=create(list);
	display(list);
}
