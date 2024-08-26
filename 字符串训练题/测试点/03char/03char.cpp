#include<cstdio>
int main()
{
	freopen("char.in","r",stdin);
	freopen("char.out","w",stdout);
	for(char i='a';i<='z';i+=2)printf("%c ",i);
	putchar('\n');
	for(char i='z';i>='a';i-=2)printf("%c ",i);
	return 0;
}
