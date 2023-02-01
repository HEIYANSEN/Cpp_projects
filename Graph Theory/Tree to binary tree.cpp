#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int l[30010],r[30010],fa[30010];
int shu[30010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		shu[i]=t;
		char temp;
		while((temp=getchar())!='\n')
		{
			if(temp==' ') continue;
			int q=temp-'0';
			fa[q]=t;
			if(l[t]==0) l[t]=q;
			else {
				int w=l[t];
				while(r[w])
					w=r[w];
				r[w]=q;
				fa[q]=w;
			}
		}	
	}
	sort(shu+1,shu+n+1);
	for(int i=1;i<=n;i++)
	{
		printf("%d %d %d %d\n",shu[i],fa[shu[i]],l[shu[i]],r[shu[i]]);
	}
	return 0;
}
