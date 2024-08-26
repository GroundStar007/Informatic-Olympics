#include <cstdio>
int n,m,room,key,num[100009][109],flag,x,x1;
int g[100009][109],h[100009][109],l,summ;
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d",&n,&m); //共有n层楼，一层楼m个房间 
	for(int i=1;i<=n;i++)//循环输入每层楼的情况 
	{
		l=0;//一层楼有楼梯的房间数 
		for(int j=1;j<=m;j++)//循环输入每个房间的情况 
		{
			scanf("%d%d",&flag,&num[i][j]);//输入每个房间的情况 
			if(flag==1)//如果有楼梯 
			{
				g[i][++l]=j;//g[i][j]存储第i层第j个有楼梯的房间号 
				h[i][j]=l;//h[i][j]存储第i层第j个房间前有几个楼梯 
			}else h[i][j]=l+1; 
		}
		g[i][0]=l;
	}
	scanf("%d",&room);//输入初始房间号
 
	room++;//本算法计数从1开始，题目从零开始，所以要++ 
	for(int i=1;i<=n;i++)
	{
		summ+=num[i][room];
		summ%=20123;
		x=num[i][room]%g[i][0];
		if(h[i][room]>g[i][0]) x1=1;
		else x1=h[i][room];
		x1=x1+x-1;
		if(x1==0)x1=g[i][0];
		else if(x1>g[i][0])x1-=g[i][0];
		room=g[i][x1];
	}
	printf("%d",summ);
	return 0;
}
