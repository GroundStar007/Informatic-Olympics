#include<bits/stdc++.h>
using namespace std;
int x;
struct sd
{
    int num,val; //�洢��źʹ�С
};
deque<sd> que;
deque<sd> que1;
int add[3][1000005]; //���Դ洢�𰸵�----������
int main()
{
    int n,m,k,cnt=1;
    cin>>n>>k;
    sd rr;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);  //����
        rr.num=i; rr.val=x;  //��ֵ
        while(!que.empty()&&x>=que.back().val)
        que.pop_back();  //�������еĲ������Ա�֤����
        while(!que1.empty()&&x<=que1.back().val)
        que1.pop_back();
        que.push_back(rr); //ѹ�����
        que1.push_back(rr);//ͬ��
        while(i-k>=que.front().num)  //T�����ڷ�Χ�ڵ�
        que.pop_front();
        while(i-k>=que1.front().num)
        que1.pop_front(); //ͬ��
        if(i>=k) 
        {
            add[0][cnt]=que.front().val;
            add[1][cnt]=que1.front().val;
            cnt++;
        } //���
    }
    for(int i=1;i<cnt;i++)
    printf("%d ",add[1][i]);
    printf("\n");
    for(int i=1;i<cnt;i++)
    printf("%d ",add[0][i]);  //���
    return 0;
}
