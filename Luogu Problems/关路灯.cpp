#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[51][51][2];
int a[51];
int sum[51];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int b;
		scanf("%d%d",&a[i],&b);
		sum[i]=sum[i-1]+b;
	}
	memset(f,0x3f,sizeof(f));
	f[k][k][0]=f[k][k][1]=0;
	for(int l=2;l<=n;l++)
	{
		for(int i=1;l+i-1<=n;i++)
		{
			int j=l+i-1;
			f[i][j][0]=min(f[i+1][j][0]+(a[i+1]-a[i])*(sum[i]+sum[n]-sum[j]),f[i+1][j][1]+(a[j]-a[i])*(sum[i]+sum[n]-sum[j]));
    		f[i][j][1]=min(f[i][j-1][0]+(a[j]-a[i])*(sum[i-1]+sum[n]-sum[j-1]),f[i][j-1][1]+(a[j]-a[j-1])*(sum[i-1]+sum[n]-sum[j-1]));
		}
	}
	printf("%d",min(f[1][n][1],f[1][n][0]));
	return 0;
}
