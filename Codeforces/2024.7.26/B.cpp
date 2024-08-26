#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1009;
int f[N][N];
vector<int> v[N];
int main() {
    freopen("test.txt", "r", stdin);
    int T;
    cin >> T;
    while (T --) {
        // memset(f, 0, sizeof f);
        int n, k, a;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a;
                if (i % k == 1 && j % k == 1)
                    cout << a;
            }
            cout << "\n";
        }
    }
    return 0;
}
