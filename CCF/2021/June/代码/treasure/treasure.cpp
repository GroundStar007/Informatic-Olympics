#include <cstdio>
int n,m,room,key,num[100009][109],flag,x,x1;
int g[100009][109],h[100009][109],l,summ;
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d",&n,&m); //����n��¥��һ��¥m������ 
	for(int i=1;i<=n;i++)//ѭ������ÿ��¥����� 
	{
		l=0;//һ��¥��¥�ݵķ����� 
		for(int j=1;j<=m;j++)//ѭ������ÿ���������� 
		{
			scanf("%d%d",&flag,&num[i][j]);//����ÿ���������� 
			if(flag==1)//�����¥�� 
			{
				g[i][++l]=j;//g[i][j]�洢��i���j����¥�ݵķ���� 
				h[i][j]=l;//h[i][j]�洢��i���j������ǰ�м���¥�� 
			}else h[i][j]=l+1; 
		}
		g[i][0]=l;
	}
	scanf("%d",&room);//�����ʼ�����
 
	room++;//���㷨������1��ʼ����Ŀ���㿪ʼ������Ҫ++ 
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
