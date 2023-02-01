#include<iostream>
using namespace std;
unsigned int binary[100],grey[100]; 
int main()
{
	unsigned long long int n,k;
	cin>>n>>k;
	int num = 0;
	while(k){
		binary[++num] = k % 2;
		k /= 2;
	}
	grey[num] = binary[num];
	for(int i =num-1 ;i >=1 ;i--) grey[i] = (binary[i+1]&(~binary[i]))|(binary[i]&(~binary[i+1]));
	for(int i = n;i>=1;i--) cout<<grey[i];
	return 0;
}
