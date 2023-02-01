#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=1000010;
struct node{
	int next,t;
}edge[5000010];
int sign[5000010][3];
int num=0,head[N];
int cnt=0;
void add(int f,int t)
{
	edge[++num].t=t;
	edge[num].next=head[f];
	head[f]=num;
}
int dfn[N],low[N],vis[N],sta[N],sd[N];
bool ru[N],chu[N];
int tim=0,q=0;
void tarjan(int x)
{
	dfn[x]=low[x]=++tim;
	vis[x]=1;
	sta[++q]=x;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].t;
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y]==1)
		{
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x])
	{
		int y;
		cnt++;
		while(sta[q]!=x)
		{
			y=sta[q];
			sd[y]=cnt;
			vis[y]=2;
			q--;
		}
		sd[x]=cnt;
		vis[x]=2;
		q--;
	}
}
int k=0;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		while(1)
		{
			scanf("%d",&t);
			if(t==0) break;
			add(i,t);
			sign[++k][1]=i;
			sign[k][2]=t;
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=k;i++)
	{
		if(sd[sign[i][1]]!=sd[sign[i][2]])
		{
			ru[sd[sign[i][1]]]=1;
			chu[sd[sign[i][2]]]=1;
		}
	}
	int w=0,e=0;
	for(int i=1;i<=cnt;i++)
	{
		if(ru[i]==0) w++;
		if(chu[i]==0) e++;
	}
	if(cnt==1) printf("1\n0");
	else printf("%d\n%d",e,max(w,e));
	return 0;
}
