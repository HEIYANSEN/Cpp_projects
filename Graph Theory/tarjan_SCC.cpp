#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
struct node{
	int next,t;
}edge[10000001];
int head[100001],num=0;
void add(int f,int t)
{
	edge[++num].t=t;
	edge[num].next=head[f];
	head[f]=num;
}
int low[100001],dfn[100001];
int quan[100001];
int v[100001];
int tim=0;
stack<int> p;
int sd[100001];
int p[100001];
void tarjan(int x)
{
	low[x]=dfn[x]=++tim;
	p.push(x);
	v[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].t;
		if(v[y]==0)
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(v[y])
		{
			low[x]=min(low[x],low[y]);
		}
	}
	if(dfn[x]==low[x])
	{
		int y;
		while(p.size())
		{
			y=p.top();
			p.pop();
			v[y]=1;
			sd[y]=x;
			if(x==y) break;
			p[x]+=p[y];
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&quan[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int f,t,v;
		scanf("%d%d",&f,&t);
		add(f,t);
	}
	return 0;
 } 
