#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=1000010;
struct node{
	int t,next;
}edge[2*N];
int num=0,head[N];
void add(int f,int t)
{
	edge[++num].t=t;
	edge[num].next=head[f];
	head[f]=num;
}
int low[N],dfn[N],tim=0,cut[N];
int root;
void tarjan(int x)
{
	dfn[x]=low[x]=++tim;
	int flag=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].t;
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[y],low[x]);
			cout<<y<<","<<low[y]<<","<<x<<endl;
			if(dfn[x]<=low[y])
			{
				flag++;
				if(x!=root) cut[x]=1;
				else if(x==root&&flag>2) cut[x]=1;
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int f,t;
		scanf("%d%d",&f,&t);
		add(f,t);
		add(t,f);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i]){
			root=i;
			tarjan(root);
		}
	}
	cout<<dfn[1];
	for(int i=1;i<=n;i++) if(cut[i]) printf("%d\n",i);
	return 0;
}
