#include<cstdio>
#include<cstring>
#include<algorithm>
const int inf=200001;
using namespace std;
int n;
int c[inf];
int b[inf];
int y[inf];
int lowbit(int x){return ( x &-x );}
void add(int x,int a)
{
	int z=n-x+1;
	while(z<=n)
	{
		b[z]+=a;
		z+=lowbit(z);
	}
	while(x<=n)
	{
		c[x]+=a;
		x+=lowbit(x);
	}
}
long long int getsmall(int x)
{
	long long int sum=0;
	while(x)
	{
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum-1;
}
long long int getbig(int x)
{
	x=n-x+1;
	long long int sum=0;
	while(x)
	{
		sum+=b[x];
		x-=lowbit(x);
	}
	return sum-1;
}
long long int ls[inf],lb[inf],rb[inf],rs[inf];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&y[i]);
	}
	long long int ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
	{
		add(y[i],1);
		ls[i]=getsmall(y[i]);
		rb[i]=getbig(y[i]);
	}
	memset(c,0,sizeof(c));
	memset(b,0,sizeof(b));
	for(int i=n;i>=1;i--)
	{
		add(y[i],1);
		rs[i]=getsmall(y[i]);
		lb[i]=getbig(y[i]);
	}
	for(int i=1;i<=n;i++)
	{
		ans1+=lb[i]*rb[i];
		ans2+=ls[i]*rs[i];
	}
	printf("%lld %lld",ans1,ans2);
	return 0;
}
