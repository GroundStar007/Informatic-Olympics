//���ֶ�ͷһ�����ֵ   ��Сֵ

//   1 1 2 3 4 3 
//   ˫�˶��У���ͷһ�������Сֵ �������ֵ��  m
//   �Ӷ�ͷ���ӵ�һ�������㳤��Ҫ��ġ�
//   �Ӷ�β��ȥ��һ��ʧЧ�����ݡ�

#include <iostream>
#include <deque>
using namespace std;
const int N=1000010;
int a[N];
deque<int>dq;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		while(dq.size()&&a[dq.back()]>=a[i])
		{
		    dq.pop_back();	
		}
		dq.push_back(i);
		//�Ӷ�ͷ����
		while(i-dq.front()>=k)dq.pop_front();
		if(i>=k)
		{
			printf("%d ",a[dq.front()]);
		} 
	}
	printf("\n");
	dq.clear();
	for(int i=1;i<=n;i++)
	{
		while(dq.size()&&a[dq.back()]<=a[i])
		{
			dq.pop_back();
		}
		dq.push_back(i);
		while(i-dq.front()>=k)dq.pop_front();
		if(i>=k)
		{
			printf("%d ",a[dq.front()]);
		}
	}
	return 0;
 }  
