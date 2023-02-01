#include<iostream>
using namespace std;
long long int dfs(int n,int k)
{
	int t=n%k;
	if(t==0) return k;
	return dfs(k,t);
}
int main()
{
	long long int n,k;
	cin>>n>>k;
	long long int ans=dfs(n,k);
	cout<<ans;
	return 0;
}
