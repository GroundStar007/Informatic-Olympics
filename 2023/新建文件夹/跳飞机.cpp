//   �ӵ�1�����ӿ�ʼ���������i�����ӵ����ֵ�� b[i]
//    �� num[i]
//     ��  dis[i]-r   dis[i]-l ֮����Щ���Ե����ֵj
//        b[i]=b[j]+num[i]; 
//   ��һ����������ֵ  ��Сֵ   �������� 

#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
const int N=500010;
long long b[N];//b[i]:����㵽���i�����ӵķ����� 
deque<int>dq; 
int dis[N],num[N];//�������������  dis[i]:����㵽��i����ľ���
int main()
{
  memset(b,128,sizeof(b));
  int n,l,r;
  cin>>n>>l>>r;
  for(int i=1;i<=n;i++)
  {
  	scanf("%d %d",&dis[i],&num[i]); 
  }
  b[0]=0;
  int now=0;
  long long ans=0;
  for(int i=1;i<=n;i++)
  {
     //����dis[now]+L<=dis[i]�ĸ������
	 while(dis[now]+l<=dis[i])
	 {
	       //now���֮ǰ
		   while(dq.size()&&b[dq.back()]<=b[now])
		   {
		   	   dq.pop_back();
		   }
		   dq.push_back(now);
		   now++; 
	 }	
	 //����  dis[dq.front()]+r<dis[i]
	    while(dq.size()&&dis[dq.front()]+r<dis[i])
		{
			dq.pop_front();
		} 
		//�������еĸ��� ���� dis[j]+l<=dis[i]  dis[j]+r>=dis[i]
		if(dq.size())b[i]=b[dq.front()] + num[i];
		ans=max(ans,b[i]);
  }	
  cout<<ans;
  return 0;
} 
