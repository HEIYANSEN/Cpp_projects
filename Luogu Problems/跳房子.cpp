#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
	int w;
	int x;
}a[500010];
long long int f[500010];
int n,d,k;
int nl=0;
int fen(int l,int r)
{
	if(l==r) return l;
	int mid=(l+r)/2;
	int s,b;
	if(mid>=d) s=1;
	else s=d-mid;
	b=d+mid;
	memset(f,-0x3f,sizeof(f));
	f[0]=0;
	bool sign=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[i].x-a[j].x>=s&&a[i].x-a[j].x<=b) 
				f[i]=max(f[j]+a[i].w,f[i]);
			else if(a[i].x-a[j].x>b) break;
		}
		if(f[i]>=k){sign=1;break;} 
	}
	if(sign) fen(l,mid);
	else fen(mid+1,r);
}
int main()
{
	scanf("%d%d%d",&n,&d,&k);
	long long int sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].w);
		if(a[i].w>0) sum+=a[i].w;
	}
	if(sum<k) {printf("-1");return 0;}
	printf("%d",fen(0,1500));
	return 0;
}
