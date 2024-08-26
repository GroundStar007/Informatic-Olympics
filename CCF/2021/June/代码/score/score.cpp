#include <bits/stdc++.h>
using namespace std;
int n,m,line,peo,ans;
struct volunteer{
	int num,score;
}a[50009];
int main()
{
	freopen("score10.in","r",stdin);
//	freopen("score.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i].num,&a[i].score);
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1-i;j++)
			if(a[j].score<a[j+1].score||(a[j+1].score==a[j].score&&a[j].num>a[j+1].num))
				swap(a[j],a[j+1]);
//	for(int i=0;i<n;i++)printf("%d %d\n",a[i].num,a[i].score);
	int line1=floor(m*1.5);
	line=a[line1-1].score;
	for(int i=0;i<n;i++)
		if(a[i].score>=line)ans++;
		else break;
	printf("%d %d\n",line,ans);
	for(int i=0;i<ans;i++)printf("%d %d\n",a[i].num,a[i].score);
	return 0;
}
