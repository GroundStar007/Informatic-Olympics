#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	freopen("1.txt", "r", stdin);
	int T;
	cin >> T;
	while (T --) {
		int n;
		cin >> n;
		int cnt = 0;
		if ((n / 2) % 2 == 1)
			cout << ((n/2)-1)/2+1 << "\n";
		else
			cout << n/4;
	}
	return 0;
}
