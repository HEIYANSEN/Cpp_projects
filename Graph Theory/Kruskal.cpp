#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int fa[5001];
int sign2[5001];
int num=0;
struct node{
	int f,t;
}edge[400001];
struct node2{
	int val;
	int biao;
}sign[400001];
int get(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void add(int x,int y)
{
	int r1=get(x),r2=get(y);
	if(r1!=r2) fa[r1]=r2;
}
void edge_add(int f,int t,int val)
{
	num++;
	edge[num].f=f;
	edge[num].t=t;
	sign[num].val=val;
	sign[num].biao=num;
}
bool cmp(node2 a,node2 b)
{
	return a.val<b.val;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,val;
		scanf("%d%d%d",&x,&y,&val);
		edge_add(x,y,val);
		edge_add(y,x,val);
	}
	sort(sign+1,sign+2*m+1,cmp);
	int ans=0;
	for(int i=1;i<=m*2;i++)
	{
		if(get(edge[sign[i].biao].f)!=get(edge[sign[i].biao].t))
		{
			add(edge[sign[i].biao].f,edge[sign[i].biao].t);
			sign2[edge[sign[i].biao].f]=1;
			sign2[edge[sign[i].biao].t]=1;
			ans+=sign[i].val;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(sign2[i]==0)
		{
			printf("orz");
			return 0;
		}
	}
	printf("%d",ans);
	
	return 0;
}
