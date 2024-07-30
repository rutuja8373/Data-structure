#include<stdio.h>
int cost[10][10],vi[10]={0};
int i,j,a,b,u,v,e,n,min,mincost=0;
int main()
{
   printf("\nenter limit:");
   scanf("%d",&n);
   printf("\nenter matrix:");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         scanf("%d",&cost[i][j]);
         if(cost[i][j]==0)
         	cost[i][j]=999;
      }
   }
   vi[1]=1;
   for(e=1;e<=n;e++)
   {
      for(i=1,min=999;i<=n;i++)
      {
         for(j=1;j<=n;j++)
         {
            if(cost[i][j]<min&&vi[j]==0)
            {
                min=cost[i][j];
                a=u=i;
                b=v=j;
            }
         }
      }
      if(vi[u]==0||vi[v]==0)
      {
          printf("\nedge=%d(%d %d):%d",e,u,v,min);
          mincost+=min;
          vi[v]=1;
      }
      cost[a][b]=cost[b][a]=999;
   }
   printf("\nmincost=%d",mincost);
}
