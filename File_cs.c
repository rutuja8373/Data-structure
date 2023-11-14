#include<stdio.h>
#include<stdlib.h>
struct emp
{
   char name[20];
   int age;
}a[40];
void count(struct emp a[],int n,int r)
{
    int c[40]={0},i;
    struct emp b[40];
    for(i=0;i<n;i++)
    {
        c[a[i].age]=c[a[i].age]+1;
    }
    for(i=1;i<=r;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        b[c[a[i].age]-1]=a[i];
    }
    for(i=0;i<n;i++)
    {
        a[i]=b[i];
    }
}
int main()
{
   FILE *f1;
   int i=0,n,max;
   f1=fopen("emp.txt","r");
   if(f1==NULL)
   {
      printf("File not found");
      exit(0);
   }
   while(!feof(f1))
   {
       fscanf(f1,"%s%d",a[i].name,&a[i].age);
       i++;
   }
   n=i-1;
   printf("\nOriginal emp:");
   for(i=0;i<n;i++)
   {
       printf("\n%s\t%d",a[i].name,a[i].age);
   }
   max=a[0].age;
   for(i=0;i<n;i++)
   {
       if(a[i].age>max)
       	  max=a[i].age;
   }
   count(a,n,max);
   printf("\nsorted emp:");
   for(i=0;i<n;i++)
   {
       printf("\n%s\t%d",a[i].name,a[i].age);
   }
   fclose(f1);
}
