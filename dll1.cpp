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
struct node *insertbeg(struct node *list,int num)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=list;
	list->prev=newnode;
	list=newnode;
	return list;
}
struct node *insertend(struct node *list,int num)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	newnode->data=num;
	temp=list;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
	temp=newnode;
	return list;
}
struct node *insertpos(struct node *list,int num,int pos)
{
	struct node *temp,*newnode;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(i=0,temp=list;i<pos-1&&temp!=NULL;temp=temp->next,i++);
	newnode->next=temp->next;
	temp->next->prev=newnode;
	temp->next=newnode;
	newnode->prev=temp;
	return list;
}
struct node *deletebeg(struct node *list)
{
	struct node *temp;
	temp=list;
	list=temp->next;
	free(temp);
	return list;
}
struct node *deleteend(struct node *list)
{
	struct node *temp,*temp1;
	temp=list;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	temp1=temp->next;
	temp->next=NULL;
	free(temp1);
	return list;
}
struct node *deletepos(struct node *list,int pos)
{
	struct node *temp,*temp1;
	int i;
	for(i=0,temp=list;i<pos-1&&temp!=NULL;temp=temp->next,i++);
	temp1=temp->next;
	temp->next=temp1->next;
	temp1->next->prev=temp;
	free(temp1);
	return list;
}
struct node *insert_common(struct node *list,int num,int pos)
{
	struct node *temp,*newnode;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	if(pos==1)
	{
		newnode->next=list;
		list->prev=newnode;
		list=newnode;
	}
	else
	{
		temp=list;
		for(i=0,temp=list;i<pos-1&&temp!=NULL;temp=temp->next,i++);
		newnode->next=temp->next;
		temp->next->prev=newnode;
		temp->next=newnode;
		newnode->prev=temp;
	}
	return list;
}
struct node *delete_common(struct node *list,int pos)
{
	struct node *temp,*temp1;
	int i;
	if(pos==1)
	{
		temp=list;
		list=temp->next;
		free(temp);
	}
	else
	{
		for(i=0,temp=list;i<pos-1&&temp!=NULL;temp=temp->next,i++);
		temp1=temp->next;
		temp->next=temp1->next;
		temp1->next->prev=temp;
		free(temp1);
	}
	return list;
}
int main()
{
	struct node *list=NULL;
	int ch,num,pos;
	do{
	printf("\n1-create \n2-display \n3-insert beginnong \n4-insert end\n5-insert position");
	printf("\n6-delete beginning \n7-delete position \n8-delete end");
	printf("\n9-insert common \n10-delete common");
	printf("\nenter choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:list=create(list);
		break;
	case 2:display(list);
		break;
	case 3:printf("\nEnter value to insert beginning:");
		scanf("%d",&num);
		list=insertbeg(list,num);
		break;
	case 4:printf("\nEnter value to insert end:");
		scanf("%d",&num);
		list=insertend(list,num);
		break;
	case 5:printf("\nEnter value to insert position:");
		scanf("%d",&num);
		printf("\nEnter position to insert position:");
		scanf("%d",&pos);
		list=insertpos(list,num,pos);
		break;
	case 6:list=deletebeg(list);
		break;
	case 7:printf("\nEnter position to dalete:");
		scanf("%d",&pos);
		list=deletepos(list,pos);
		break;
	case 8:list=deleteend(list);
		break;
	case 9:printf("\nEnter value to insert position:");
		scanf("%d",&num);
		printf("\nEnter position to insert:");
		scanf("%d",&pos);
		list=insert_common(list,num,pos);
		break;
	case 10:printf("\nEnter position to dalete:");
		scanf("%d",&pos);
		list=delete_common(list,pos);
		break;
	default:printf("\nInvalid Choice....");
	}
	}while(ch<11);
}
