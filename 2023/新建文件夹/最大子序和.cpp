//   1 1 2 3 4 3 
//   ˫�˶��У���ͷһ�������Сֵ �������ֵ��  m
//   �Ӷ�ͷ���ӵ�һ�������㳤��Ҫ��ġ�
//   �Ӷ�β��ȥ��һ��ʧЧ�����ݡ�

#include <iostream>
#include <deque>
using namespace std;
const int N=300010;
int s[N],a[N];
deque<int>dq;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];  //s[0]=0
	}
	dq.push_back(0);
	int ans=s[1];
	for(int i=1;i<=n;i++)
	{
		//����s[0]-s[i-1]֮���һ����Сֵ
		while(i-dq.front()>m)//�Ѷ�ͷ�����㳤��Ҫ��ĳ��Ӵ��� 
		{
			dq.pop_front();
	    }//�����whileѭ���ǴӶ�ͷ���� 
		ans=max(ans,s[i]-s[dq.front()]);
		//�Ӷ�β���
		while(dq.size()&&s[dq.back()]>=s[i])
		{
			dq.pop_back();
		} 
		dq.push_back(i);
	}
	cout<<ans;
	return 0;
 } 
