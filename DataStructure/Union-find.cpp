#include<cstdio>
using namespace std;
int father[10001];
int find(int n)
{
	if(father[n]==n) return n;
	return father[n]=find(father[n]);
}
void he(int x,int y)
{
	int i=find(x),j=find(y);
	father[i]=j;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&z,&x,&y);
		if(z==2)
		{
			if(find(x)==find(y)) printf("Y\n");
			else printf("N\n");
		}
		if(z==1) he(x,y);
	}
	return 0;
}
