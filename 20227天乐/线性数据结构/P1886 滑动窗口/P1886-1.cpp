#include<bits/stdc++.h>
using namespace std;
int x;
struct sd
{
    int num,val; //存储编号和大小
};
deque<sd> que;
deque<sd> que1;
int add[3][1000005]; //用以存储答案的----见代码
int main()
{
    int n,m,k,cnt=1;
    cin>>n>>k;
    sd rr;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);  //输入
        rr.num=i; rr.val=x;  //赋值
        while(!que.empty()&&x>=que.back().val)
        que.pop_back();  //单调队列的操作，以保证单调
        while(!que1.empty()&&x<=que1.back().val)
        que1.pop_back();
        que.push_back(rr); //压入队列
        que1.push_back(rr);//同上
        while(i-k>=que.front().num)  //T掉不在范围内的
        que.pop_front();
        while(i-k>=que1.front().num)
        que1.pop_front(); //同上
        if(i>=k) 
        {
            add[0][cnt]=que.front().val;
            add[1][cnt]=que1.front().val;
            cnt++;
        } //存答案
    }
    for(int i=1;i<cnt;i++)
    printf("%d ",add[1][i]);
    printf("\n");
    for(int i=1;i<cnt;i++)
    printf("%d ",add[0][i]);  //输出
    return 0;
}
