#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
// ���� + ��� 
map < string, int > mp;
bool ok_num(string num, int max_num) { // �ж��ַ��� num ��ʾ�������Ƿ�Ϸ� 
	if (num.length() == 0) { // û���� ... 
		return false;
	} else if (num[0] == '0' && num.length() >= 2) { // ��ǰ���� 
		return false;
	} else if (num.length() >= 6) { // ���ֹ��� 
		return false;
	} else {
		int x = 0;
		for (int i = 0; i < num.length(); i++) {
			x = (x * 10) + num[i] - 48;
		}
		return x < max_num; // �Ƿ��ڷ�Χ�� 
	}
}
bool ok(string IP) {
	// �� . �� : ��ȡ���� 
	string asdf;
	for (int i = 0; i < IP.length(); i++) {
		if (IP[i] == '.' || IP[i] == ':') {
			asdf += IP[i];
		}
	}
	if (asdf != "...:") { // ���Ϸ� 
		return false;
	}
	string num[5]; // �ָ��ַ��� 
	for (int cnt = 0 /*�ڼ�����*/, i = 0; i < IP.length(); i++) {
		if (IP[i] == '.' || IP[i] == ':') {
			// �����ָ��� 
			// ��һ���� 
			cnt++;
		} else {
			// �ѵ�ǰ��������ӵ�ĩβ 
			num[cnt] += IP[i];
		}
	}
	// ���Ƿ�Ϸ� 
	if (!ok_num(num[0], 256)) {
		return false;
	}
	if (!ok_num(num[1], 256)) {
		return false;
	}
	if (!ok_num(num[2], 256)) {
		return false;
	}
	if (!ok_num(num[3], 256)) {
		return false;
	}
	if (!ok_num(num[4], 65536)) {
		return false;
	}
	// �Ϸ� 
	return true;
}
int main() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	int n;
	scanf("%d", &n);
	string op, ad;
	for (int i = 1; i <= n; i++) {
		cin >> op >> ad;
		if (op == "Server") {
			// ����� 
			if (ok(ad)) {
				if (mp.count(ad) == 0) {
					// �ɹ��������� ! 
					printf("OK\n");
					mp[ad] = i;
				} else {
					// �õ�ַ�ѱ�ռ�� 
					printf("FAIL\n");
				}
			} else {
				// �ǺϷ���ַ�� 
				printf("ERR\n");
			}
		} else {
			// �ͻ��� 
			if (ok(ad)) {
				// �Ϸ���ַ�� 
				if (mp.count(ad) == 0) {
					// δ�ҵ������ 
					printf("FAIL\n");
				} else {
					// �ɹ��������� ! 
					printf("%d\n", mp[ad]);
				}
			} else {
				// �ǺϷ���ַ�� 
				printf("ERR\n");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 100 �� 
