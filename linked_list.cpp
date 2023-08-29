#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *create(struct node *list)
{
	int i,n;
	struct node *temp,*newnode;
	printf("enter limit:");
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
			temp=newnode;
		}
	}
	return list;
}
struct node *insertbeg(struct node *list,int num)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=list;
	list=newnode;
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
int main()
{
	struct node *list=NULL;
	int ch,num;
	do{
	printf("\n1-create\n2-display\n3-insert beggining\nenter choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:list=create(list);
			break;
		case 2:display(list);
			break;
		case 3:printf("\nenter num to insert at beginning:");
			   scanf("%d",&num);
			   list=insertbeg(list,num);
			break;
		default:printf("\nInvalid choice...");
	}
     }while(ch<4);
}
