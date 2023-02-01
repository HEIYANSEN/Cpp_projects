#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int l[101],r[101],sign[101],sum[101],fa[101],bian[101];
int edge[101][101];
int quan[101][101];
void bianli(int x,int f)
{
	fa[x]=f;
	for(int i=1;i<=sign[x];i++)
	{
		int y=edge[x][i];
		if(y==f) continue;
		bianli(y,x);
		if(l[x]==0) l[x]=y;
		else if(r[x]==0) r[x]=y;
		sum[x]+=sum[y]+quan[x][y];
		bian[x]+=bian[y]+1;
	}
}
int f[101][101];
int dp(int x,int j)
{
	if(j>bian[l[x]]+bian[r[x]]+2) return -1e9;
	if(bian[x]==0&&j!=0) return -1e9;
	if(f[x][j]!=0) return f[x][j];
	if(j==0) return f[x][j]=sum[x];
	for(int i=0;i<=j;i++)
	{
		if(bian[l[x]]>=j-i&&bian[r[x]]>=i)
		f[x][j]=max(dp(l[x],j-i)+dp(r[x],i)+quan[x][l[x]]+quan[x][r[x]],f[x][j]);
	}
	f[x][j]=max(f[x][j],max(dp(r[x],j-bian[l[x]]-1)+quan[x][r[x]],dp(l[x],j-bian[r[x]]-1)+quan[x][l[x]]));
	return f[x][j];
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n-1;i++)
	{
		int a,b,num;
		scanf("%d%d%d",&a,&b,&num);
		edge[a][++sign[a]]=b;
		edge[b][++sign[b]]=a;
		quan[a][b]=num;
		quan[b][a]=num;
	}
	bianli(1,1);
	printf("%d",dp(1,n-1-q));
	return 0;
}
