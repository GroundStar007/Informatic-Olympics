#include<iostream>
#include<cstring>
using namespace std;
int x,y,len,len1,len2,limit,ans;
string s1,s2;
int main()
{
//	freopen("ring5.in","r",stdin);
//	freopen("ring5.out","w",stdout);
    cin>>s1>>s2;
    len1=s1.size();    
    len2=s2.size();
    limit=min(len1,len2);    //����ַ����ĳ���
    s1+=s1; // �컷
    s2+=s2; // �컷
	for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++)
		{
            len=0;
            x=i;
            y=j;
            while(s1[x++]==s2[y++]&&len<limit)
				len++;//���ܳ����γ�
            if(len>ans)ans=len;
        }
    cout<<ans;
    return 0;
}
