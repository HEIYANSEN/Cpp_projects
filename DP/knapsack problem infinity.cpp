#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
	int dp[20001]={0};
	int w[51];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}

	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
	}
	printf("%d",n-dp[n]);
	return 0;
}

