#include<iostream>
using namespace std;
int a[100000001],b[100000001];
void merge(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	merge(l,mid);
	merge(mid+1,r);
	int k=l,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	if(a[i]>a[j]) b[k++]=a[j++];
	else b[k++]=a[i++];
	while(j<=r) b[k++]=a[j++];
	while(i<=mid) b[k++]=a[i++];
	for(int h=l;h<=r;h++)
	a[h]=b[h];
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	merge(1,n);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	return 0;
}