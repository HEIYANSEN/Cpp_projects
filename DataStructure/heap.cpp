#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
class ren{
	public:
		int age;
		int gender;
	private:
		int ID;
	
};
queue<int> q;
int num = 0;
int heap[100001];
void insert(int node){
	if(node == 0) return;
	int fa = (node-1)/2;
	if(heap[fa] > heap[node]){
		swap(heap[fa],heap[node]);
		insert(fa);
	}
}
int get(){
	return heap[0];
}
void pop(int node){
	if(node == 0){
		heap[node] = heap[num-1];
		num--;
	}
	int l = node*2 + 1;
	int r = node*2 + 2;
	if(l > num ) return;
	if(r > num){
		if(heap[r]<heap[node]) swap(heap[r],heap[node]);
	}
	else{
		int to = l;
		if(heap[r]<heap[l])
			to = r;
		if(heap[node] > heap[to]){
			swap(heap[node],heap[to]);
			pop(to);
		}
	}
	
}
int main()
{
	for(int i =0;i<5;i++)
	{
		cin>>heap[i];
		insert(i);
		num++;
	}
	for(int i = 0;i<5;i++)
	{
		printf("%d ",get());
		pop(0);
	}
	
	return 0;
}
