//����ģ������ 
#include<iostream>
using namespace std;
int next[1000005];
int main(){
    int n,m;
    cin>>n>>m;//����n��m
    for(int i=0;i<n;i++)//��ʼ��
    	next[i]=i+1;
	next[n]=1;
	int p=0;
	for(int i=1;i<=n;i++){//��ʼģ���Ȧ����
		for(int j=1;j<m;j++)
			p=next[p];//pλ������
		cout<<p[next]<<" ";//�����Ȧ�˵�λ��
		next[p]=next[next[p]];//ɾ����Ȧ��
	}
	return 0;
}
