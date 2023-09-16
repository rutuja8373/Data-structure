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
	int n,i;
	printf("Enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(NODE*)malloc(sizeof(NODE));
		printf("\nEmter value:");
		scanf("%d",&newnode->data);
		if(list==NULL)
		{
			list=temp=newnode;
			newnode->next=list;
		}
		else
		{
			temp->next=newnode;
			newnode->next=list;
			temp=newnode;
		}
	}	
	return list;
}
void display(NODE *list)
{
	NODE *temp=list;
	do{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp!=list);
}
int main()
{
	NODE *list=NULL;
	list=create(list);
	display(list);
}
