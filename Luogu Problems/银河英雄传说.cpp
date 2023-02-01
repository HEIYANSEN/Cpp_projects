#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int fa[30001];
int front[30001];
int num[30001];
int ask(int x)
{
	if(fa[x]==x) return x;
	int fn=ask(fa[x]);
	front[x]+=front[fa[x]];
	return fa[x]=fn;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=30000;i++)
	{
		fa[i]=i;
		num[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		char op;
		int x,y;
		cin>>op;
		scanf("%d%d",&x,&y);
		int fx=ask(x);
		int fy=ask(y);
		if(op=='C')
		{
			if(fx!=fy) printf("-1\n");
			else printf("%d\n",abs(front[x]-front[y])-1);
		}
		if(op=='M')
		{
			front[fx]+=num[fy];
			num[fy]+=num[fx];
			fa[fx]=fa[fy];
			num[fx]=0;
		}
	}
	return 0;
}
