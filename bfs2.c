#include<stdio.h>
#define MAX 100
struct queue
{
   int data[MAX];
   int front,rear;
}q;
void init()
{
    q.rear=q.front=-1;
}
int isfull()
{
    return(q.rear==MAX-1);
}
int isempty()
{
    return(q.front==q.rear);
}
int addq(int num)
{
    q.data[++q.rear]=num;
}
int delq()
{
   return(q.data[++q.front]);
}
void bfs(int a[10][10],int n)
{
    int i,j,v[10]={0};
    int level=0,node=0,total=0;
    init();
    i=1;
    addq(i);
    v[1]=1;
    while(!isempty())
    {
        i=delq();
        printf("v%d\t",i);
        for(j=1;j<=n;j++)
        {
            if(a[i][j]==1&&v[j]==0)
            {
               addq(j);
               v[j]=1;
            }
        }
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
    bfs(a,n);
}
