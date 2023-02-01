#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=1000010;
int a[N],sign[N];
struct node {
	int l,r;
	int num;
	int d;
} q[N];
bool cmp(node a,node b) {
	return a.l<b.l;
}
bool cmp2(node a,node b) {
	return a.r<b.r;
}
bool cmp3(node a,node b) {
	return a.num<b.num;
}
int L[N],R[N];
long long int ans=0;
int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].num=i;
	}
	int t=sqrt(m);
	for(int i=1; i<=t; i++) {
		L[i]=R[i-1]+1;
		R[i]=i*t;
	}
	if(R[t]<m) {
		t++;
		L[t]=R[t-1]+1;
		R[t]=m;
	}
	sort(q+1,q+1+m,cmp);
	int le=1;
	int ri=1;
	sign[a[1]]++;
	ans=1;
	for(int i=1; i<=t; i++) {
		sort(q+L[i],q+R[i]+1,cmp2);
		for(int j=L[i]; j<=R[i]; j++) {
			while(le<q[j].l) {
				ans-=sign[a[le]]*sign[a[le]];
				sign[a[le]]--;
				ans+=sign[a[le]]*sign[a[le]];
				le++;
			}
			while(le>q[j].l) {
				le--;
				ans-=sign[a[le]]*sign[a[le]];
				sign[a[le]]++;
				ans+=sign[a[le]]*sign[a[le]];
			}
			while(ri>q[j].r) {
				ans-=sign[a[ri]]*sign[a[ri]];
				sign[a[ri]]--;
				ans+=sign[a[ri]]*sign[a[ri]];
				ri--;
			} 
			while(ri<q[j].r) {
				ri++;
				ans-=sign[a[ri]]*sign[a[ri]];
				sign[a[ri]]++;
				ans+=sign[a[ri]]*sign[a[ri]];
			}
			q[j].d=ans;
		}
		
	}
	sort(q+1,q+m+1,cmp3);
	for(int i=1; i<=m; i++) {
		printf("%d\n",q[i].d);
	}
return 0;
}
