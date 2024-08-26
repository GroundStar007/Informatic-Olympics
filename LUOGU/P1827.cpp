/* 
给定二叉树的前序和中序求后序

后序为左右中，根节点最后输出 
*/

#include <iostream>
#include <cstdio>
using namespace std;

string pre,mid;

void search(int pre1,int pre2,int mid1,int mid2){
	int p=mid.find(pre[pre1]);
	if(p>mid1)search(pre1+1,pre1+p-mid1,mid1,p-1);
	if(p<mid2)search(pre1+1+p-mid1,pre2,p+1,mid2);
	printf("%c",pre[pre1]);
}

int main(){
	freopen("1.txt","r",stdin);
	cin>>mid>>pre;
	search(0,pre.size()-1,0,mid.size()-1);
	return 0;
} 
