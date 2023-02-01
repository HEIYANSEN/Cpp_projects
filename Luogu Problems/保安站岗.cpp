#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int to,next;
}edge[3001];
int head[1501],num=0;
void add(int f,int t)
{
	edge[++num].to=t;
	edge[num].next=head[f];
	head[f]=num;
}
int flag[1501],v[1501];
int f[1501][3];
// 0-父亲控制当前节点
// 1-儿子控制当前节点
// 2-自己控制当前节点 
void dfs(int x)
{
	f[x][2]=v[x];
	int must=1e9,sum=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int t=edge[i].to;
		dfs(t);
		f[x][0]+=min(f[t][2],f[t][1]);
		f[x][2]+=min(f[t][2],min(f[t][1],f[t][0]));
		if(f[t][2]>f[t][1])
		{
			must=min(must,f[t][2]-f[t][1]);
			f[x][1]+=f[t][1];
		}
		else
		{
			f[x][1]+=f[t][2];
			sum++;
		}
	}
	if(sum==0)
	{
		f[x][1]+=must;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t,k,m;
		scanf("%d%d%d",&t,&k,&m);
		for(int j=1;j<=m;j++)
		{
			int to;
			scanf("%d",&to);
			add(t,to);
			flag[to]=1;
		}
		v[t]=k;
	}
	int root;
	for(int i=1;i<=n;i++)
		if(flag[i]==0) {root=i;break;}
	dfs(root);
	printf("%d",min(f[root][0],min(f[root][1],f[root][2])));
	return 0;
}
