#include<iostream>
#include<cstdio>
using namespace std;
int c[500001];
int lowbit(int x){return (x & -x);}
int n,m;
void add(int a,int x)
{
	while(x<=n)
	{
		c[x]+=a;
		x+=lowbit(x);
	}
}
int ask(int x)
{
	int ans=0;
	while(x)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		add(a,i);
	}
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1) add(c,b);
		if(a==2) printf("%d\n",ask(c)-ask(b-1));
	}
	return 0;
}
