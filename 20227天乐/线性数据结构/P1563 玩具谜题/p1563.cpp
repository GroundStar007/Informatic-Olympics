/*
ѭ�����м�¼n����
0��ʾ����Ȧ�ڣ������Ӧλ�ü�С�����Ҷ�Ӧλ������
1��ʾ����Ȧ�⣬�����Ӧλ���������Ҷ�Ӧλ�ü�С�� 
*/
#include <cstdio>
const int maxn=100010;
int n,m,q[maxn];	//q[i]:��i���˵ĳ��� 
int d,k;			//d:0-����;1-���� 
char ss[maxn][15];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d%s",&q[i],ss[i]);
	int cur=0;
	for(int i=0;i<m;i++){
		scanf("%d%d",&d,&k);
		if(q[cur]==d) cur=(cur-k+n)%n;
		else cur=(cur+k)%n;
	}
	printf("%s\n",ss[cur]);
	return 0;
}
