#include<iostream>
using namespace std;
int a[100][2],x,cn=0;
bool b[1000]={0};
void dfs(int i)//����
{
	if(i>x)
	cn++;//��������˶��õ����Լ�ϲ�����飬�������ͼ�һ
	else for(int j=0;j<=1;j++)
		if(!b[a[i][j]])//�ֱ��ж�ÿ����ϲ���ĵ�һ���͵ڶ������Ƿ񱻱������ߣ����û�У��Ͱ��Ȿ��������
			{
				b[a[i][j]]=1;//���Ȿ��ֵΪ���ù�
				dfs(i+1);//�õ���������һ
				b[a[i][j]]=0;//�����жϵڶ���
			}
}
int main()
{
	cin>>x;//��������
	if(x==0)//���У����Ե�Ӧ���������
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=x;i++)
	cin>>a[i][0]>>a[i][1];//����ÿ����ϲ�õ���
	dfs(1);
	cout<<cn;
}
