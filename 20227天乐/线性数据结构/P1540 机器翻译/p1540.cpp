/*
����ѭ������
ά��ÿ�������ڶ����е�λ�ã������ѯ��
�����ڶ����У�λ����-1��ʾ 
*/
#include <cstdio>
const int maxm=110;
const int maxn=1010; 
int m,n,p[maxn],k,ans;
int q[maxm],head,tail;	//ѭ������ 
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<maxn;i++) p[i]=-1;
	scanf("%d",&k);
	head=0; tail=1%m; q[0]=k;
	p[k]=0; ans=1;
	for(int i=1;i<n;i++){
		scanf("%d",&k);
		if(p[k]==-1){
			ans++;
			if(head==tail){		//������ 
				p[q[head]]=-1;	//���׳���
				head=(head+1)%m; 
			} 
			//k���
			q[tail]=k; p[k]=tail;
			tail=(tail+1)%m;
		}
	}
	printf("%d\n",ans);
	return 0;
}

