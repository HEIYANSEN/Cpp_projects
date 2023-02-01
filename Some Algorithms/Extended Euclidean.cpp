#include<cstdio>
using namespace std;
long long int exgcd(long long int a,long long int b,long long int &x1,long long int &y1)
{
	if(b==0)
	{
		x1=1,y1=0;
		return a;
	}
	long long int d=exgcd(b,a%b,x1,y1);
	long long int temp=x1;
	x1=y1,y1=temp-y1*(a/b);
	return d;
}
long long int abs(long long int x){if(x<0) return -x;}
int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	long long int x,y;
	long long int tp=exgcd(a,b,x,y);
	long long int ans=(x%b+b)%b;
	printf("%lld",ans);
	return 0;
}
