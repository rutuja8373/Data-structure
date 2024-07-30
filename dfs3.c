#include<stdio.h>
void dfs(int a[10][10],int n,int i)
{
    int j;
    static int v[10]={0};
    v[i]=1;
    printf("v%d\t",i);
    for(j=1;j<=n;j++)
    {
       if(a[i][j]==1&&v[j]==0)
       {
           dfs(a,n,j);
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
    dfs(a,n,1);
}
