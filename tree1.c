#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node *left,*right;
}NODE;
NODE *create(NODE *root)
{
   NODE *temp,*newnode,*parent;
   int i,n;
   printf("\nEnter limit:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      newnode=(NODE*)malloc(sizeof(NODE));
      printf("\nEnter value:");
      scanf("%d",&newnode->data);
      newnode->left=NULL;
      newnode->right=NULL;
      if(root==NULL)
      {
          root=newnode;
      }
      else
      {
          temp=root;
          while(temp!=NULL)
          {
              parent=temp;
              if(temp->data>newnode->data)
              	  temp=temp->left;
              else
              	  temp=temp->right;
          }
          if(parent->data>newnode->data)
            parent->left=newnode;
          else
            parent->right=newnode;
      }
   }
   return root;
}
void inorder(NODE *root)
{
   NODE *temp=root;
   if(temp!=NULL)
   {
       inorder(temp->left);
       printf("%d\t",temp->data);
       inorder(temp->right);
   }
}
void preorder(NODE *root)
{
   NODE *temp=root;
   if(temp!=NULL)
   {
       printf("%d\t",temp->data);
       preorder(temp->left);
       preorder(temp->right);
   }
}
void postorder(NODE *root)
{
   NODE *temp=root;
   if(temp!=NULL)
   {
       postorder(temp->left);
       postorder(temp->right);
       printf("%d\t",temp->data);
   }
}
int main()
{
  NODE *root=NULL;
  root=create(root);
  printf("\nTree Display Using Inorder:");
  inorder(root);
  printf("\nTree Display Using Preoredr:");
  preorder(root);
  printf("\nTree Display Using Postorder:");
  postorder(root);
}
