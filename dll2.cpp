#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next,*prev;
}NODE;
NODE *create(NODE *list)
{
	NODE *temp,*newnode;
	int i,n,num;
	printf("Enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(NODE*)malloc(sizeof(NODE));
		printf("\nEnter value:");
		scanf("%d",&num);
		newnode->data=num;
		newnode->next=NULL;
		if(list==NULL)
		{
			list=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp->next;
			temp=newnode;
		}
	}
	return list;
}
void display(NODE *list)
{
	NODE *temp;
	for(temp=list;temp!=NULL;temp=temp->next)
	{
		printf("%d\t",temp->data);
	}
}
int main()
{
	NODE *list=NULL;
	list=create(list);
	display(list);
}
