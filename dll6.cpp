#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next,*prev;
};
struct node *create(struct node *list)
{
	struct node *temp,*newnode;
	int i,n;
	printf("Entre limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter value:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(list==NULL)
		{
			list=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
 	}
	return list;
}
void display(struct node *list)
{
	struct node *temp;
	for(temp=list;temp!=NULL;temp=temp->next)
	{
		printf("%d\t",temp->data);
	}
}
void sort(node *list)
{
	int t;
	node *i,*j;
	for(i=list;i!=NULL;i=i->next)
	{
		for(j=list;j!=i;j=j->next)
		{
			if(i->data<j->data)
			{
				t=i->data;
				i->data=j->data;
				j->data=t;
			}
		}
	}
	printf("\nsorted linked list:");
	display(list);	
}
int main()
{
	node *list=NULL;
	list=create(list);
	display(list);
	sort(list);
}
