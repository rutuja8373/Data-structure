#include<stdio.h>
#include<stdlib.h>
#define memory (node*)malloc(sizeof(node))
typedef struct node
{
   int data;
   struct node *next,*prev;
}node;
struct node *create(node *list)
{
  node *temp,*newnode;
  int i,n;
  printf("\nEnter limit:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
     newnode=memory;
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
void display(node *list)
{
  node *temp;
  for(temp=list;temp!=NULL;temp=temp->next)
  {
     printf("%d\t",temp->data);
  }
}
node *revdisplay(node *list)
{
  node *prev=NULL,*current=list,*next=NULL;
  while(current!=NULL)
  {
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
  }
  return prev;
}
int main()
{
  int ch,num;
  node *list=NULL;
  do{
   printf("\n1-create\n2-display\n3-reverse the list");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:list=create(list);
     		break;
     case 2:display(list);
     		break;
     case 3:list=revdisplay(list);
     		break;
   }
  }while(ch<4);
}
