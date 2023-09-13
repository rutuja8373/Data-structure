//use linear search in singly linked list...

#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *create(NODE *list)
{
	NODE *temp,*newnode;
	int n,num,i;
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
NODE *search(NODE *list)
{
	int i,x;
	NODE *temp;
	printf("\nEnter value to search:");
	scanf("%d",&x);
	for(temp=list;temp!=NULL;temp=temp->next)
	{
		if(temp->data==x)
		{
			printf("\nfound..");
			break;
		}
	}
	if(temp==NULL)
	{
		printf("\nnot found..");
	}
}
int main()
{
	NODE *list=NULL;
	list=create(list);
	display(list);
	search(list);
}
