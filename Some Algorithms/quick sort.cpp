#include<cstdio>
#include<algorithm>
using namespace std;
int a[100001];
void qsort(int l,int r){
	if(l==r) return;
	int lp = l;
	int rp = r;
	int sign = a[(l+r)/2];
	while(lp<rp){
		while(a[lp]<sign) lp++;
		while(a[rp]>sign) rp--;
		if(lp<=rp) {
			swap(a[lp],a[rp]);
			lp++;
			rp--;
		}
	}
	if(l<rp) qsort(l,rp);
	if(r>lp) qsort(lp,r);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);	
	qsort(1,n);
	for(int i=1 ;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
