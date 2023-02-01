#include<algorithm>
#include<cmath>
using namespace std;
int a[110][110];
long long int f[110][110];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
		}
	}
	long long int ans=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int h=0;i+h<=n&&j+h<=m;h++)
			{
				long long int temp=f[i+h][j+h]-f[i+h][j]-f[i][j+h]+f[i][j];
				if((h+1)*(h+1)==temp) ans=max(ans,temp);
			}
		}
	}
	ans=sqrt(ans);
	printf("%d",ans);
	return 0;
}
