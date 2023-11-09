#include<stdio.h>
#include<stdlib.h>
#define memory (struct node*)malloc(sizeof(struct node))
typedef struct node
{
  int data;
  struct node *next;
}node;
node *create(node *list)
{
   int i,n;
   node *temp,*newnode;
   printf("Enter Limit:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      newnode=memory;
      printf("Enter value:");
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
void display(node *list)
{
   node *temp=list;
  for(temp=list;temp!=NULL;temp=temp->next)
  {
  	printf("%d\t",temp->data);
  }
}
int sort(node *list)
{
	node *i,*j,*temp;
	int t;
	for(i=list;i!=NULL;i=i->next)
	{
		for(j=i;j!=NULL;j=j->next)
		{
			if(i->data>j->data)
			{
				t=i->data;
				i->data=j->data;
				j->data=t;
			}
		}
	}
	printf("\nSorted list");
	 for(temp=list;temp!=NULL;temp=temp->next)
  {
  	printf("%d\t",temp->data);
  }
}
int main()
{
	int ch;
	node *list=NULL;
	do{
		printf("\n1-create\n2display");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:list=create(list);
					break;
			case 2:display(list);
					break;
			case 3:sort(list);
					break;
		}
	}while(ch<4);
}
