#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node *next;
}node;
struct node *head[10];
node *create(int a[10][10],int n)
{
    int i,j;
    node *temp,*newnode;
    for(i=1;i<=n;i++)
    {
        head[i]=NULL;
        for(j=1;j<=n;j++)
        {
           if(a[i][j]==1)
           {
              newnode=(node*)malloc(sizeof(node));
              newnode->data=j;
              newnode->next=NULL;
              if(head[i]==NULL)
              {
                 head[i]=newnode;
                 temp=newnode;
              }
              else
              {
                  temp->next=newnode;
                  temp=newnode;
              }
           }
        }
    }
}
void display(int n)
{
   int i;
   node *temp;
   for(i=1;i<=n;i++)
   {
      printf("\nHEAD[%d]->",i);
      for(temp=head[i];temp!=NULL;temp=temp->next)
      {
          printf("v%d->\t",temp->data);
      }
      printf("NULL");
   }
}
int main()
{
   int a[10][10],i,j,n;
   printf("\nenter limit:");
   scanf("%d",&n);
   printf("\nenter matrix:");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         scanf("%d",&a[i][j]);
      }
   }
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
       {
          printf("%d\t",a[i][j]);
       }
       printf("\n");
   }
   create(a,n);
   display(n);
}
