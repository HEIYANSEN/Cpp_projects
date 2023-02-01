#include<cstdio>
#define ll long long
using namespace std;
ll int exgcd(ll int a,ll int b,ll int &x1,ll int &y1)
{
	if(b==0)
	{
		x1=1,y1=0;
		return a;
	}
	ll int d=exgcd(b,a%b,x1,y1);
	ll int temp=x1;
	x1=y1,y1=temp-y1*(a/b);
	return d;
}
int main()
{
	ll x,y,m,n,l;
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	ll h=y-x;
	ll w=m-n;
	ll k,z;
	if(w<0)
	{
		w=-w;
		h=-h;
	}
	ll d=exgcd(w,l,k,z);
	if(h%d!=0)
	{
		printf("Impossible");
		return 0;
	}
	k*=h/d;
	printf("%lld",(k%(l/d)+(l/d))%(l/d));
	return 0;
}
