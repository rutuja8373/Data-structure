#include<stdio.h>
int cost[10][10],parent[10];
int i,j,a,b,u,v,e,n,min,mincost=0;
int find(int u)
{
   while(parent[u])
   	u=parent[u];
   	return u;
}
int check(int u,int v)
{
   if(u!=v)
   {
       parent[v]=u;
       return 1;
   }
   return 0;
}
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
   for(e=1;e<n;e++)
   {
      for(i=1,min=999;i<=n;i++)
      {
         for(j=1;j<=n;j++)
         {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                a=u=i;
                b=v=j;
            }
         }
      }
      u=find(u);
      v=find(v);
      if(check(u,v))
      {
          printf("\nedge=%d(%d %d):%d",e,a,b,min);
          mincost+=min;
      }
      cost[a][b]=cost[b][a]=999;
   }
   printf("\nmincost=%d",mincost);
}
