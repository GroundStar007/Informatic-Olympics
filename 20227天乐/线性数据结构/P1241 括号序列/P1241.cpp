#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
char str[N];
int vis[N];//����Ƿ�ƥ��ɹ�

int main()
{
	cin >> str;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ')')
		{
			for (int j = i - 1; j >= 0; j--)
				if (!vis[j] && (str[j] == '[' || str[j] == '('))//�ҵ������δƥ���������
				{
					if (str[j] == '(') vis[i] = vis[j] = 1;//���ƥ��ɹ����ǣ�����ƥ��ʧ��
					break;
				}
		}
		else if (str[i] == ']')
		{
			for(int j = i - 1; j >= 0; j--)
				if (!vis[j] && (str[j] == '[' || str[j] == '('))
				{
					if (str[j] == '[') vis[i] = vis[j] = 1;
					break;
				}
		}
	}
	for (int i = 0; str[i]; i++)
		if (vis[i]) cout << str[i];
		else if (str[i] == '(') cout << str[i] << ')';
		else if (str[i] == ')') cout << '(' << str[i];
		else if (str[i] == '[') cout << str[i] << ']';
		else if (str[i] == ']') cout << '[' << str[i];
	return 0;
}
