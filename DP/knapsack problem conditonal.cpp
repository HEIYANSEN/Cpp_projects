#include<cstdio>
#include<algorithm>
#include<iostream>
struct thing{
	int c;
	int w;
	int sign;
}a[61][5000];
int num[61];
int dp[32001];
using namespace std;
int main()
{
	int n,m,t;
	scanf("%d%d",&n,&m);
	t=m;
	for(int i=1;i<=m;i++)
	{
		int x,y,q;
		scanf("%d%d%d",&x,&y,&q);
		if(q==0)
		{
			num[i]=1;
			a[i][1].w=x;
			a[i][1].c=x*y;
			a[i][1].sign=1;
		}
		else if(q!=0)
		{
			int nl=num[q];
			for(int j=1;j<=num[q];j++)
			{
				if(a[q][j].sign<=2)
				{
					a[q][++nl].w=a[q][j].w+x;
					a[q][nl].c=a[q][j].c+x*y;
					a[q][nl].sign=a[q][j].sign+1;
				}
			}
			num[q]=nl;
		}
	}
	for(int i=1;i<=t;i++)
	{
		if(num[i]==0) continue;
		for(int j=n;j>=0;j-=10)
		{
			for(int k=1;k<=num[i];k++)
			{
				if(j>=a[i][k].w) dp[j]=max(dp[j],dp[j-a[i][k].w]+a[i][k].c);
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
}
