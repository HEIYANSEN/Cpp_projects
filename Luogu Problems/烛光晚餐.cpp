#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int x;
	int y;
	int c;
}p[101];
int f[1001][1001];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].c);
		p[i].x+=500;
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=p[i].c;j--)
		{
			for(int h=0;h<=p[i].x;h++)
			{
				f[j][h]=max(f[j][h],f[j-p[i].c][h+p[i].x]+p[i].y);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
