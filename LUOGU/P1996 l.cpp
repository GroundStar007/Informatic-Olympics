#include <iostream>
#include <cstdio>
using namespace std;

int m,n;
struct Node{ // 链表结构
    int data;
    Node *next;
}*head,*tail,*p,*temp;

int main(){
    scanf("%d%d",&n,&m);
    head=new Node;
    head->next=NULL;
    tail=head;  // 首尾相接
    for(int i=1;i<=n;i++){
        p=new Node; // 新申请一个
        p->data=i; // 设置编号；
        p->next=NULL; // 末尾next指针指向空
        tail->next=p; // 接到tail的后面
        tail=p; // tail指向新接上的p
    }
    p=head->next; // 将p指向首元素
    tail->next=head->next; // 首尾链接
    for(int i=1;i<=n;i++){
        for(int j=1;j<m-1;j++) // 移到第m-1个
            p=p->next; // 不断后移
        printf("%d ",p->next->data); // 输出出队编号
        p->next=p->next->next; // 删除
        p=p->next; // 向后移
    }
    return 0;
}
