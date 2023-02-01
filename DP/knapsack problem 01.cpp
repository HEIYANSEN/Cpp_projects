#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int dp[1001]={0};
	int w[101],c[101];
	int t,m;
	scanf("%d%d",&t,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&w[i],&c[i]);
	for(int i=1;i<=m;i++)
		for(int j=t;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
	printf("%d",dp[t]);
	return 0;
}