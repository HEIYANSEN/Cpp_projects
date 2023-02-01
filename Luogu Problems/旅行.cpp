#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct node{
	int next,t;
}edge[10001];
int head[10001];
int num=0;
int ru[5001];
int flag[10001];
int sign=0;
void add(int f,int t)
{
	edge[++num].t=t;
	edge[num].next=head[f];
	head[f]=num;
}
void dfs(int x,int fa)
{
	priority_queue<int> q;
	printf("%d ",x);
	for(int i=head[x];i;i=edge[i].next)
	{
		int t=edge[i].t;
		if(t==fa) continue;
		q.push(-t);
	}
	while(q.size())
	{
		int t=-q.top();
		q.pop();
		dfs(t,x);
	}
}
void search(int x,int fa)
{
	if(sign) return;
	ru[x]++;
	if(ru[x]==2) {sign=x;return;}
	for(int i=head[x];i;i=edge[i].next)
	{
		int t=edge[i].t;
		if(t==fa) continue;
		search(t,x);
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
	memset(flag,0x3f,sizeof(flag));
//	dfs(1,-1);
	search(1,-1);
	printf("%d",sign);
	return 0;
}
