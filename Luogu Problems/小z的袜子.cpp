#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int c[50010];
long long int f[50010];
int l[50010],r[50010];
int pos[50010];
int flag[50010];
struct node{
	int co[250];
	int sum[250];
	int a;
}k[50010];
long long int fi(int x)
{
	if(x==1) return f[x]=1;
	if(f[x]!=0) return f[x];
	return f[x]=fi(x-1)+x;
}
long long int cmp(long long int a,long long int b)
{
 	long long int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int temp[500010]={0};
void check(int L,int R)
{
	long long int ans=0;
	int p=pos[L],q=pos[R];
	memset(temp,0,sizeof(temp));
	memset(flag,0,sizeof(flag));
	if(p==q)
	{
		int num=0;
		for(int i=l[p];i<=r[p];i++)
		{
			if(flag[c[i]]==0) flag[c[i]]=++num;
			temp[flag[c[i]]]++;
		}
		for(int i=1;i<=num;i++)	if(temp[i]>=2) ans+=fi(temp[i]-1);
		long long int h=cmp(ans,fi(l[p]-r[p]+1));
		printf("lld/lld\n",ans/h,fi(R-L)/h);
	}
	int num=0;
	for(int i=p+1;i<=q-1;i++)
	{
		for(int j=1;j<=k[i].a;j++)
		{
			if(flag[k[i].co[j]]==0) flag[k[i].co[j]]=++num;
			temp[flag[k[i].co[j]]]+=k[i].sum[j];
		}
	}
	for(int i=L;i<=r[p];i++)
	{
		if(flag[c[i]]==0) flag[c[i]]=++num;
		temp[flag[c[i]]]++;
	}
	for(int i=l[q];i<=R;i++)
	{
		if(flag[c[i]]==0) flag[c[i]]=++num;
		temp[flag[c[i]]]++;
	}
	for(int i=1;i<=num;i++) for(int i=1;i<=num;i++)	if(temp[i]>=2) ans+=fi(temp[i]-1);
	long long int h=cmp(fi(R-L),ans);
	cout<<ans<<","<<fi(R-L)<<endl;
	printf("%lld/%lld\n",ans/h,fi(R-L)/h);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	int t=sqrt(n);
	for(int i=1;i<=t;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=i*t;
	}
	if(r[t]<n) t++,l[t]=r[t-1]+1,r[t]=n;
	for(int i=1;i<=t;i++)
	{
		int sign=0;
		memset(flag,0,sizeof(flag));
		for(int j=l[i];j<=r[i];j++)
		{
			if(flag[c[j]]==0) flag[c[j]]=++sign;
			k[i].co[flag[c[j]]]=c[j];
			k[i].sum[flag[c[j]]]++;
			pos[j]=i;
		}
		k[i].a=sign;
	}
	while(m--)
	{
		int L,R;
		scanf("%d%d",&L,&R);
		if(L==R){printf("0/1\n");continue;}
		check(L,R);
	}
	return 0;
} 
