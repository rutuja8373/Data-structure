#include<stdio.h>
#include<stdlib.h>
#define memory (node*)malloc(sizeof(node))
typedef struct node
{
  int coef;
  int exp;
  struct node *next;
}node;
node *create(node *p1)
{
   node *new,*temp;
   int i,n;
   printf("\nEnter no of terms:");
   scanf("%d",&n);
   new=memory;
   printf("\nEnter coefficient:");
   scanf("%d",&new->coef);
   printf("\nEnter exponent:");
   scanf("%d",&new->exp);
   temp=new;
   for(i=1;i<n;i++)
   {
      temp->next=memory;
      temp=temp->next;
      printf("\nEnter coefficient:");
      scanf("%d",&temp->coef);
      printf("\nEnter exponent:");
      scanf("%d",&temp->exp);
   }
   temp->next=NULL;
   return new;
}
node *add(node *p1,node *p2)
{
  node *t1=p1,*t2=p2,*t3=NULL,*p3=NULL;
  node *new;
   while(t1!=NULL&&t2!=NULL)
   {
      new=memory;
      new->next=NULL;
      if(t1->exp < t2->exp)
      {
         new->coef=t1->coef;
         new->exp=t1->exp;
         t1=t1->next; 
      }
      else if(t1->exp >t2->exp)
      {
         new->coef=t2->coef;
         new->exp=t2->exp;
         t2=t2->next;
      }
      else
      {
         new->coef=t1->coef+t2->coef;
         new->exp=t1->exp;
         t1=t1->next;
         t2=t2->next;
      }
      if(t3==NULL)
      {
        t3=p3=new;
      }
      else
      {
         t3->next=new;
         t3=t3->next;
      }
   }
   while(t1!=NULL)
   {
      new=memory;
      new->next=NULL;
      new->coef=t1->coef;
      new->exp=t1->exp;
      t1=t1->next;
   }
   while(t2!=NULL)
   {
      new=memory;
      new->next=NULL;
      new->coef=t2->coef;
      new->exp=t2->exp;
      t2=t2->next;
   }
   return p3;
}
void display(node *p1)
{
   node *temp;
   for(temp=p1;temp!=NULL;temp=temp->next)
   {
     printf("%d^%d+",temp->coef,temp->exp);
   }
}
int main()
{
node *p1=NULL,*p2=NULL,*p3=NULL;
  p1=create(p1);
  p2=create(p2);
  p3=add(p1,p2);
  
  printf("\nFIRST POLYNOMIAL:");
  display(p1);
  printf("\nSECOND POLYNOMIAL:");
  display(p2);
  printf("\nADDITION OF POLYNOMIAL:");
  display(p3);
}
