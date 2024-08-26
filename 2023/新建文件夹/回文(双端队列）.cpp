#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
deque<int>dql,dqr;
const int N=1000010;
int a[N];
char s[N];//L L R R
struct Node
{
	int b,e;
}f[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int n;

	memset(f,0,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		scanf("%d",&a[i]); 
		if(f[a[i]].b==0)
		{
			f[a[i]].b=i;
		}
		else
		{
			f[a[i]].e=i;
		}
	}
	int t=f[a[1]].e;
	int c=1;
	s[c]='L';
	s[2*n-c+1]='L';
	dql.clear();
	dqr.clear();
	for(int i=2;i<t;i++)
	{
		dql.push_back(a[i]);
	}
	for(int i=2*n;i>t;i--)
	{ 
	    dqr.push_back(a[i]);
	}
	while(dql.size()||dqr.size())
	{
		
		int i=0,j=-1,x=0,y=-1;
		if(dql.size())
		{
			i=dql.front();
			j=dql.back();
			if(dql.size()==1)j=-1;
		}
		if(dqr.size())
		{
			x=dqr.front();
			y=dqr.back();
			if(dqr.size()==1)y=-1; 
			                                                  
		}
		if(i==j||i==y||i==x&&dqr.size()==1)
		{
			if(i==j)  //i=0  j=0
		    {
		    	c++;
		    	s[c]='L';
		    	s[2*n-c+1]='L';
		    	dql.pop_front();
				dql.pop_back(); 
			}
			else
			{
				c++;
		    	s[c]='L';
		    	s[2*n-c+1]='R';
		    	dql.pop_front();
				dqr.pop_back();
			}
		}
		else if(x==y||x==j||(x==i&&dql.size()==1))
		{
			if(x==y)
			{
				c++;
				s[c]='R';
		    	s[2*n-c+1]='R';
		    	dqr.pop_front();
				dqr.pop_back(); 
			}
			else
			{
				c++;
				s[c]='R';
		    	s[2*n-c+1]='L';
		    	dqr.pop_front();
				dql.pop_back(); 
			}
		}
		else break;
	}

	if(dql.empty()&&dqr.empty()){
		for(int i=1;i<=2*n;i++)
			printf("%c",s[i]);
		printf("\n");
	}
	else
	{
		dql.clear();
		dqr.clear(); 
		c=1;
	    int t=f[a[2*n]].b;
		for(int i=1;i<t;i++)
		{
		    dql.push_back(a[i]);	
		}
		for(int i=2*n-1;i>t;i--)
		{
			dqr.push_back(a[i]);
		}	
		s[c]='R';
		s[2*n-c+1]='L';
		while(dql.size()||dqr.size())
	{
		
		int i=0,j=-1,x=0,y=-1;
		if(dql.size())
		{
			i=dql.front();
			j=dql.back();
			if(dql.size()==1)j=-1;
		}
		if(dqr.size())
		{
			x=dqr.front();
			y=dqr.back();
			if(dqr.size()==1)y=-1;                                                   
		}
		if(i==j||i==y||i==x&&dqr.size()==1)
		{
			if(i==j)
		    {
		    	c++;
		    	s[c]='L';
		    	s[2*n-c+1]='L';
		    	dql.pop_front();
				dql.pop_back(); 
			}
			else
			{
				c++;
		    	s[c]='L';
		    	s[2*n-c+1]='R';
		    	dql.pop_front();
				dqr.pop_back();
			}
		}
		else if(x==j||x==y||x==i&&dql.size()==1)
		{
			if(x==y)
			{
				c++;
				s[c]='R';
		    	s[2*n-c+1]='R';
		    	dqr.pop_front();
				dqr.pop_back(); 
			
			}
			else
			{
		       	c++;
				s[c]='R';
		    	s[2*n-c+1]='L';
		    	dqr.pop_front();
				dql.pop_back(); 
		         
			}
		}
		else
		{
			break;
		}
	}
		if(dql.empty()&&dqr.empty())
		{
			for(int i=1;i<=2*n;i++)
			{
				printf("%c",s[i]);
			}
			printf("\n");
		}
		else
		{
			printf("-1\n");
		}
	}
}
	return 0;
 } 
