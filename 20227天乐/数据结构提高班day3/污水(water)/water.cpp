#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULI;

const int N=100005;
int n,m;
int dego[N],degi[N],g[N][10];

const int L=8,BS=int(pow(10,L));
int p[4]={2,3,5,7};
struct number
{
	int l;	
	ULI a[10];
	number (ULI x=0)
	{
		l=0;
		memset(a,0,sizeof(a));
		for(;x>=BS;x/=BS)a[++l]=x%BS;	
		a[++l]=x;	
	}
	void print()const
	{
		printf("%llu",a[l]);
		for(int i=l-1;i>=1;i--)
		{
			int ln=1;
			for(ULI j=a[i];j>=10;j/=10)ln++;
			for(;ln<L;ln++)printf("%c",'0');
			printf("%llu",a[i]);
		}
	}
	const number operator + (const number& x)const
	{
		number res;
		ULI ad=0;
		res.l=max(l,x.l);
		for(int i=1;i<=res.l;i++)
		{
			ad+=a[i]+x.a[i];
			res.a[i]=ad%BS;ad/=BS;
		}
		for(;ad;ad/=BS)res.a[++res.l]=ad%BS;
		return res;
	}
	const number operator * (const number& x)const
	{
		number res;
		res.l=l+x.l-1;
		for(int i=1;i<=l;i++)
			for(int j=1;j<=x.l;j++)
				res.a[i+j-1]+=a[i]*x.a[j];
		ULI ad=0;
		for(int i=1;i<=res.l;i++)
		{
			ad+=res.a[i];
			res.a[i]=ad%BS;ad/=BS;
		}
		for(;ad;ad/=BS)res.a[++res.l]=ad%BS;
		while(res.l>1&&!res.a[res.l])res.l--;
		return res;
	}
	const pair<number,ULI> operator / (ULI x)const
	{
		number res=*this;
		ULI ad=0;
		for(int i=res.l;i>=1;i--)
		{
			ad+=res.a[i];
			res.a[i]=ad/x;ad=ad%x*BS;
		}
		while(res.l>1&&!res.a[res.l])res.l--;
		return make_pair(res,ad);
	}
};
struct frac
{
	number fp,fq;
	frac (number _fp=number(),number _fq=number(1)){fp=_fp;fq=_fq;}
	void print()const
	{
		fp.print();
		printf("%c",' ');
		fq.print();
	}
	const frac operator / (ULI x)const{return frac(fp,fq*number(x));}
	const frac operator + (const frac& x)const
	{
		frac res(fp*x.fq+x.fp*fq,fq*x.fq);
		for(int i=0;i<4;i++)
			while(1)
			{
				auto resp=res.fp/p[i],resq=res.fq/p[i];
				if(!resp.second&&!resq.second)res.fp=resp.first,res.fq=resq.first;else break;					
			}		
		return res;
	}
};
frac f[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",dego+i);
		for(int j=1;j<=dego[i];j++)scanf("%d",&g[i][j]),degi[g[i][j]]++;
	}
	queue<int> q;
	for(int i=1;i<=m;i++)f[i]=frac(number(1),number(1)),q.push(i);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(!dego[u])continue;
		f[u]=f[u]/dego[u];
		for(int i=1;i<=dego[u];i++)
		{
			int v=g[u][i];
			f[v]=f[v]+f[u];
			if(!(--degi[v]))q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
		if(!dego[i])f[i].print(),puts("");
	return 0;
}
