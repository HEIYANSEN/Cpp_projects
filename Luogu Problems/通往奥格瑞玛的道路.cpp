#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,b;
int f[10001];
struct node{
	int t,next,v;
}edge[100010];
int num=0,head[10001]={0};
void add(int f,int t,int x)
{
	num++;
	edge[num].t=t;
	edge[num].v=x;
	edge[num].next=head[f];
	head[f]=num;
}
long long int dis[10001];
priority_queue <pair<int,int> > q;
bool dijikstra(int x)
{
	if(f[1]>x||f[n]>x) return 0;
	memset(dis,127,sizeof(dis));
	dis[1]=0;
	int sign[10001]={0};
	q.push(make_pair(0,1));
	for(int i=1;i<=n;i++)
			if(f[i]>x) sign[i]=1;
	while(q.size())
	{
		int s=q.top().second;
		q.pop();
		if(sign[s]==1) continue;
		sign[s]=1;
		for(int i=head[s];i;i=edge[i].next)
		{
			int to=edge[i].t;
			if(dis[to]>dis[s]+edge[i].v)
			{
				dis[to]=dis[s]+edge[i].v;
				q.push(make_pair(-dis[to],to));
			}
			
		}
	}
	//918720190435737471
	if(dis[n]>b) return 0;
	else return 1; 
}
int ans=1e9;
void fen(int l,int r)
{
	if(r<=l) return;
	int mid=(l+r)/2;
	bool a=dijikstra(mid);
	if(a)
	{
		ans=mid;
		fen(l,mid);
	}
	else
	{
		fen(mid+1,r);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&b);
	int l=1e9,r=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		l=min(l,f[i]);
		r=max(r,f[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int f,t,x;
		scanf("%d%d%d",&f,&t,&x);
		add(f,t,x);
		add(t,f,x);
	}
	if(dijikstra(r)==0)
	{
		printf("AFK");
		return 0;
	}
	ans=r;
	fen(l,r);
	printf("%d",ans);
	return 0;
}
