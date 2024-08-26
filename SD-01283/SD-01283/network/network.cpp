#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
// 判重 + 编号 
map < string, int > mp;
bool ok_num(string num, int max_num) { // 判断字符串 num 表示的数字是否合法 
	if (num.length() == 0) { // 没有数 ... 
		return false;
	} else if (num[0] == '0' && num.length() >= 2) { // 有前导零 
		return false;
	} else if (num.length() >= 6) { // 数字过大 
		return false;
	} else {
		int x = 0;
		for (int i = 0; i < num.length(); i++) {
			x = (x * 10) + num[i] - 48;
		}
		return x < max_num; // 是否在范围内 
	}
}
bool ok(string IP) {
	// 把 . 和 : 抽取出来 
	string asdf;
	for (int i = 0; i < IP.length(); i++) {
		if (IP[i] == '.' || IP[i] == ':') {
			asdf += IP[i];
		}
	}
	if (asdf != "...:") { // 不合法 
		return false;
	}
	string num[5]; // 分割字符串 
	for (int cnt = 0 /*第几个数*/, i = 0; i < IP.length(); i++) {
		if (IP[i] == '.' || IP[i] == ':') {
			// 遇到分隔符 
			// 下一个数 
			cnt++;
		} else {
			// 把当前的数字添加到末尾 
			num[cnt] += IP[i];
		}
	}
	// 数是否合法 
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
	// 合法 
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
			// 服务机 
			if (ok(ad)) {
				if (mp.count(ad) == 0) {
					// 成功建立连接 ! 
					printf("OK\n");
					mp[ad] = i;
				} else {
					// 该地址已被占用 
					printf("FAIL\n");
				}
			} else {
				// 非合法地址串 
				printf("ERR\n");
			}
		} else {
			// 客户机 
			if (ok(ad)) {
				// 合法地址串 
				if (mp.count(ad) == 0) {
					// 未找到服务机 
					printf("FAIL\n");
				} else {
					// 成功加入连接 ! 
					printf("%d\n", mp[ad]);
				}
			} else {
				// 非合法地址串 
				printf("ERR\n");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 100 分 
