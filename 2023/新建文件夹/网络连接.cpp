#include <iostream>
#include <unordered_map>
#include <map>
#include <cstring>
using namespace std;
map <string,int> mp;//地址 ——> 服务器编号 
int n;
string op,ad;
bool check(string s)
{
	int cnt1=0,cnt2=0,cnt3=0; //cnt1为'.'的个数，cnt2为':'的个数，cnt3为当前是第几个数字 
	long long num=0;//存储每一个数字 
	for(int i=0;i<s.size();i++)
	{
		if((!i||s[i-1]=='.'||s[i-1]==':')&&s[i]>='0'&&s[i]<='9') //判断当前为第几个数字 
			cnt3++;
		if(s[i]=='.'||s[i]==':')
		{
			if(s[i]=='.')
				cnt1++;  //'.'的个数加1 
			if(s[i]==':')
				cnt2++;  //':'的个数加1 
			if(cnt1<3&&cnt2)  //':'出现在'.'之前 
				return false;
			if(!cnt3)        //第一个字符不是数字 
				return false;
			if(cnt3<5&&(num<0||num>255))//前四个数的范围不对 
				return false;
			num=0;
		}
		else if(s[i]<'0'||s[i]>'9')  //出现除'.'、':'、数字以外的其他字符 
			return false;
		else if(i&&!num&&s[i-1]=='0') //判断前导0 
			return false;
		else
			num=num*10+s[i]-'0';
	}
	if(num<0||num>65535||cnt1!=3||cnt2!=1||cnt3!=5) //判断最后一个数的范围，'.'的个数，':'的个数,数字的个数 
		return false;
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>op>>ad;
		if(check(ad))//判断地址格式是不是合法 
		{
			if(op=="Server")//服务器 
			{
				if(!mp[ad])//当前服务器是第一个发出该地址的 
				{
					printf("OK\n");
					mp[ad]=i; //当前地址对应的服务器编号为i 
				}	
				else if(mp[ad]>0) //在当前服务器之前已经有服务器发出过该地址 
					printf("FAIL\n");
			}
			else//客户机 
			{
				if(mp[ad])  //当前客户机想要连接的地址，已经被服务器发出过 
					printf("%d\n",mp[ad]); //连接到对应的服务器 
				else
					printf("FAIL\n");  //当前客户机想要连接的地址，还没有服务器发出 
			}
		}
		else //地址不合法 
			printf("ERR\n");
	}
	return 0;
}
