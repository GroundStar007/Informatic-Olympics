#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char a[19],b[1000009];
int lena,lenb,o,o1,len[100009],cnt,j,cnt1,ans,ans1=-1;
bool flag=true;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin.getline(a,11);
	cin.getline(b,1000001);
	lenb=strlen(b);
	lena=strlen(a);
	strlwr(a);
	strlwr(b);
	
	for(int i=0;i<lenb;i++)
		if(b[i]!=' '){
			o=0;
			for(j=i;b[j]!=' ';j++)o++;
			if(o==lena){
				len[ans]=i;
				ans++;
			}
			i=j-1;
		}

	for(int i=0;i<ans;i++){
		flag=true;
		for(j=len[i],o1=0;o1<lena;j++,o1++)
			if(a[o1]!=b[j]){
				flag=false;
				break;
			}
		if(flag==true){
			cnt++;
			if(ans1==-1)ans1=len[i];
		}
	}

	if(ans1==-1)printf("-1");
	else printf("%d %d",cnt,ans1);
	return 0;
}
