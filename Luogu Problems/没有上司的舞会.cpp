#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int a[6001];
int f[10001][2];
int flag[10001];
struct node{
	vector<int>son;
	int num;
	node()
	{
		num=0;
	}
}r[6001];
int dp(int x,int s)
{
	if(f[x][s]!=0) return f[x][s];
	vector<int>::iterator it;
	if(s==1)
	{
		if(r[x].num)
		for(it=r[x].son.begin();it!=r[x].son.end();it++)
			f[x][s]+=dp(*it,0);
		f[x][s]+=a[x];
	}
	else
	{
		if(r[x].num)
		for(it=r[x].son.begin();it!=r[x].son.end();it++)
		{
			f[x][s]+=max(dp(*it,0),dp(*it,1));
		}
		
	}
	return f[x][s];
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=1,k=1;
	while(l!=0&&k!=0)
	{
		scanf("%d%d",&l,&k);
		r[k].son.push_back(l);
		flag[l]=1;
		r[k].num++;
	}
	int root;
	for(int i=1;i<=n;i++)
		if(flag[i]==0){root=i;break;}
	printf("%d",max(dp(root,0),dp(root,1)));
	return 0;
}
