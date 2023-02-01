#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int a[1000001];
long long int sum[100001];
int l[100001],r[100001],pos[100001];
int n,m,t;
long long int add[100001];
long long int check(int L,int R)
{
	long long int ans=0;
	int p=pos[L],q=pos[R];
	if(p==q)
	{
		for(int i=L;i<=R;i++)
			ans+=a[i];
		ans+=add[q]*(R-L+1);
		return ans;
	}
	for(int i=p+1;i<=q-1;i++)
		ans+=sum[i]+add[i]*(r[i]-l[i]+1);
	for(int i=L;i<=r[p];i++) ans+=a[i];
	ans+=add[p]*(r[p]-L+1);
	for(int i=l[q];i<=R;i++) ans+=a[i];
	ans+=add[q]*(R-l[q]+1);
	return ans;
}
void ad(int L,int R,int d)
{
	int p=pos[L],q=pos[R];
	if(p==q)
	{
		for(int i=L;i<=R;i++) a[i]+=d;
		sum[p]+=d*(R-L+1);
		return;
	}
	for(int i=p+1;i<=q-1;i++) add[i]+=d;
	for(int i=L;i<=r[p];i++) a[i]+=d;
		sum[p]+=d*(r[p]-L+1);
	for(int i=l[q];i<=R;i++) a[i]+=d;
		sum[q]+=d*(R-l[q]+1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	t=sqrt(n);
	for(int i=1;i<=t;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=i*t;
	}
	if(r[t]<n) t++,l[t]=r[t-1]+1,r[t]=n;
	for(int i=1;i<=t;i++)
	{
		for(int j=l[i];j<=r[i];j++)
		{
			sum[i]+=a[j];
			pos[j]=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int op;
		int L,R,d;
		cin>>op;
		if(op==1) 
		{
			scanf("%d%d%d",&L,&R,&d);
			ad(L,R,d);
		}
		if(op==2){
			scanf("%d%d",&L,&R);
			printf("%lld\n",check(L,R));
		}
	}
	return 0;
}
