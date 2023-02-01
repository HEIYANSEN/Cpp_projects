#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int head[100001];
int num=0;
struct node{
	int f,t,val,next;
}edge[1000001];
void add(int f,int t,int val)
{
	edge[++num].t=t;
	edge[num].val=val;
	edge[num].next=head[f];
	head[f]=num;
}
int dis[100001];
int flag[100001];
priority_queue<pair<int,int> >p;
int main()
{
	int n,m,to;
	scanf("%d%d%d",&n,&m,&to);
	for(int i=1;i<=m;i++)
	{
		int f,t,v;
		scanf("%d%d%d",&f,&t,&v);
		add(f,t,v);
	}
	memset(dis,0x3f,sizeof(dis));
	p.push(make_pair(to,0));
	dis[to]=0;
	while(p.size())
	{
		int x=p.top().first;
		p.pop();
		if(flag[x]) continue;
		flag[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int to1=edge[i].t;
			int temp=edge[i].val+dis[x];
			if(temp<dis[to1])
			{
				dis[to1]=temp;
				p.push(make_pair(to1,-temp));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dis[i]);
	}
	return 0;
}