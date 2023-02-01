#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
long long int dis[100010];
int sign[100010];
int num=0;
int head[100010];
queue<int>p;
struct node{
	int va;
	int f;
	int t;
	int next;
}edge[500010];
void add(int f,int t,int val)
{
	num++;
	edge[num].t=t;
	edge[num].va=val;
	edge[num].next=head[f];
	head[f]=num;
}
using namespace std;
int main()
{
	int n,m,g;
	scanf("%d%d%d",&n,&m,&g);
	for(int i=1;i<=m;i++)
	{
		int x,y,val;
		scanf("%d%d%d",&x,&y,&val);
		add(x,y,val);
	}
	for(int i=0;i<=n;i++)
		dis[i]=2147483647;
	p.push(g);
	sign[g]=1;
	dis[g]=0;
	while(p.empty()!=true)
	{
		for(int i=head[p.front()];i;i=edge[i].next)
		{
			if(dis[p.front()]+edge[i].va<dis[edge[i].t])
			{
				dis[edge[i].t]=dis[p.front()]+edge[i].va;
				if(sign[edge[i].t]==0) 
				{
					p.push(edge[i].t);
					sign[edge[i].t]=1;
				}
			}
		}
		sign[p.front()]=0;
		p.pop();
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",dis[i]);
	
	return 0;
}
