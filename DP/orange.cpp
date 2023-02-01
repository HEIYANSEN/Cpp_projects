#include<iostream>
#include<algorithm>
using namespace std;
int f[100000];
int main(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		f[i] = f[i-1] + 1;
		if(i%2 ==0) f[i] = min(f[i],f[i/2]+1);
		if(i%3 ==0) f[i] = min(f[i],f[i/3]+1);
	}
	cout<<f[n];
	return 0;
}
