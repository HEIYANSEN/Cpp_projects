#include<cstdio>
#include<algorithm>
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
int dfn[N],low[N],bridge[2*N],tim=0;
void tarjan(int x,int i){
	low[x]=dfn[x]=++tim;
	for(int j=head[x];j;j=edge[j].next)
	{
		int y=edge[j].t;
		if(!dfn[y])
		{
			tarjan(y,j);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x])
			{
				bridge[j]=bridge[j^1]=1;
			}
		}
		else if(j!=(i^1)) low[x]=min(low[x],dfn[y]);
	}
}
int c[N],cnt=0;
void dfs(int x)
{
	c[x]=cnt;
	for(int i=head[x];i;i=edge[i].next)
	{
		if(bridge[i]) continue;
		if(!c[edge[i].t]) dfs(edge[i].t);
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
		if(!dfn[i]) tarjan(i,0);
	for(int i=1;i<=n;i++)
	{
		if(!c[i]) dfs(i);
	}
	for(int i=1;i<=n;i++) printf("%d\n",c[i]);
	return 0;
}
