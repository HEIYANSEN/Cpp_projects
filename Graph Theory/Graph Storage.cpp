#define V 10000
#define E 100000
#include<cstdio>
int head[V];//head[i] i�Ŷ���ĳ���ٱߵı�� 
using namespace std; 
struct node{
	int to;// �������ܵ���ı��
	int dis;// �����ߵ�Ȩֵ
	int next;// ��һ���ߵı��
}edge[E];
int edge_num=0;
void add_edge(int from,int to,int dis)
{
	edge_num++;
	edge[edge_num].to=to;
	edge[edge_num].dis=dis;
	edge[edge_num].next=head[from];
	head[from]=edge_num;
}
int main()
{
	int v,e;
	scanf("%d%d",&v,&e);
	for(int i=1;i<=e;i++)
	{
		int s,t,val;
		scanf("%d%d%d",&s,&t,&val);
		add_edge(s,t,val);
		add_edge(t,s,val);
	}   
	int query;
	scanf("%d",&query);
	for(int i=head[query];i;i=edge[i].next)
	{
		printf("%d %d",edge[i].to,edge[i].dis);
	}
	
	return 0;
}
