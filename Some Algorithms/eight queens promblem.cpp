#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int hang[15],lie[15];
int m[15][15];
int n,sign=0,ans=0;
bool panduan(int i,int j)
{
	for(int k=1;i+k<=n&&j+k<=n;k++) if(m[i+k][j+k]==1) return 0;
	for(int k=1;i-k>=1&&j-k>=1;k++) if(m[i-k][j-k]==1) return 0;
	for(int k=1;i+k<=n&&j-k>=1;k++) if(m[i+k][j-k]==1) return 0;
	for(int k=1;i-k>=1&&j+k<=n;k++) if(m[i-k][j+k]==1) return 0;
	return 1;
}
void dfs(int i,int j)
{
	
	
	hang[i]=1;
	lie[j]=1;
	m[i][j]=1;
	if(j==n){
		ans++;
		if(sign<3){
			for(int k=1;k<=n;k++)
				for(int h=1;h<=n;h++) if(m[h][k]==1) printf("%d ",h);
		    sign++;
		    printf("\n");
		}
		hang[i]=0;
		lie[j]=0;
		m[i][j]=0;
		return;
	}
	for(int g=1;g<=n;g++){
		if(hang[g]==0&&lie[j+1]==0&&panduan(g,j+1))
		{
			dfs(g,j+1);
			
		}
	}
	hang[i]=0;
	lie[j]=0;
	m[i][j]=0;
	return;
}

int main()
{
	scanf("%d",&n);
	for(int k=1;k<=n;k++) dfs(k,1);
	printf("%d",ans);
	return 0;
}


