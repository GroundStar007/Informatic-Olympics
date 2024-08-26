#include <iostream>
#include <unordered_map>
#include <map>
#include <cstring>
using namespace std;
map <string,int> mp;//��ַ ����> ��������� 
int n;
string op,ad;
bool check(string s)
{
	int cnt1=0,cnt2=0,cnt3=0; //cnt1Ϊ'.'�ĸ�����cnt2Ϊ':'�ĸ�����cnt3Ϊ��ǰ�ǵڼ������� 
	long long num=0;//�洢ÿһ������ 
	for(int i=0;i<s.size();i++)
	{
		if((!i||s[i-1]=='.'||s[i-1]==':')&&s[i]>='0'&&s[i]<='9') //�жϵ�ǰΪ�ڼ������� 
			cnt3++;
		if(s[i]=='.'||s[i]==':')
		{
			if(s[i]=='.')
				cnt1++;  //'.'�ĸ�����1 
			if(s[i]==':')
				cnt2++;  //':'�ĸ�����1 
			if(cnt1<3&&cnt2)  //':'������'.'֮ǰ 
				return false;
			if(!cnt3)        //��һ���ַ��������� 
				return false;
			if(cnt3<5&&(num<0||num>255))//ǰ�ĸ����ķ�Χ���� 
				return false;
			num=0;
		}
		else if(s[i]<'0'||s[i]>'9')  //���ֳ�'.'��':'����������������ַ� 
			return false;
		else if(i&&!num&&s[i-1]=='0') //�ж�ǰ��0 
			return false;
		else
			num=num*10+s[i]-'0';
	}
	if(num<0||num>65535||cnt1!=3||cnt2!=1||cnt3!=5) //�ж����һ�����ķ�Χ��'.'�ĸ�����':'�ĸ���,���ֵĸ��� 
		return false;
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>op>>ad;
		if(check(ad))//�жϵ�ַ��ʽ�ǲ��ǺϷ� 
		{
			if(op=="Server")//������ 
			{
				if(!mp[ad])//��ǰ�������ǵ�һ�������õ�ַ�� 
				{
					printf("OK\n");
					mp[ad]=i; //��ǰ��ַ��Ӧ�ķ��������Ϊi 
				}	
				else if(mp[ad]>0) //�ڵ�ǰ������֮ǰ�Ѿ��з������������õ�ַ 
					printf("FAIL\n");
			}
			else//�ͻ��� 
			{
				if(mp[ad])  //��ǰ�ͻ�����Ҫ���ӵĵ�ַ���Ѿ��������������� 
					printf("%d\n",mp[ad]); //���ӵ���Ӧ�ķ����� 
				else
					printf("FAIL\n");  //��ǰ�ͻ�����Ҫ���ӵĵ�ַ����û�з��������� 
			}
		}
		else //��ַ���Ϸ� 
			printf("ERR\n");
	}
	return 0;
}
