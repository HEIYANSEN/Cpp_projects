#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
struct node{
	int next;
	int t;
}edge[1000001];
int num=0;
int cnt[1000001];
int head[1000001];
void add(int f,int t)
{
	num++;
	edge[num].t=t;
	edge[num].next=head[f];
	head[f]=num;
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
		cnt[t]++;
	}
	queue<int> p;
	for(int i=1;i<=n;i++)
		if(cnt[i]==0) p.push(i);
	while(p.empty()!=true)
	{
		printf("%d ",p.front());
		for(int i=head[p.front()];i;i=edge[i].next)
		{
			cnt[edge[i].t]--;
			if(cnt[edge[i].t]==0) 
			{
				p.push(edge[i].t);
			}
		}
		p.pop();
	}
	return 0;
}
