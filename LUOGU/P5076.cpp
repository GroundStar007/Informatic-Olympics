#include <iostream>
#include <cstdio>
#include <algorithm>
#define MIN -2147483647
#define MAX 2147483647
using namespace std;
int n,a,b,num[100009],len;

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		if(a==1){
			int k=lower_bound(num+1,num+1+len,b)-num;
            //���ֲ���x��ע�ⷵ��ֵ��ָ�����Ҫ��ȥa
			printf("%d\n",k);
		}
		if(a==2)printf("%d\n",num[b]);
		if(a==3){
			int k=lower_bound(num+1,num+1+len,b)-num;
			printf("%d\n",num[k-1]);
		}
		if(a==4){
			int k=upper_bound(num+1,num+1+len,b)-num;
			if(k!=len+1)printf("%d\n",num[k]);
    		//�ҵõ������
			else printf("%d\n",MAX);
		}
		if(a==5){
			int k=lower_bound(num+1,num+1+len,b)-num;
			if(k==len+1)num[++len]=b;
			else{
				for(int i=len;i>=k;i--)
					num[i+1]=num[i];
				num[k]=b;
				len++;
			}
		}
	}
	return 0;
}
