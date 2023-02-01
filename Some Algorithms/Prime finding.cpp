#include<cstdio>
using namespace std;
bool isq[100000010];
int prime[100000010];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int num = 0;
	for(int i = 2 ;i<=n;i++){
		if(!isq[i]){
			prime[++num] = i;
		}
		for(int j = 1;j<=num&&i*prime[j]<=n;j++){
			isq[i*prime[j]] = 1;
			if(i%prime[j]==0) break;
		}
	}
	for(int i = 1;i<=k;i++){
		int t;
		scanf("%d",&t);
		printf("%d\n",prime[t]);
	} 
	return 0;
}
