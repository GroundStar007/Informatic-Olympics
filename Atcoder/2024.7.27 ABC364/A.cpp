#include <iostream>
#include <cstdio>
using namespace std;
int n;
string s;
bool flag = false, l = false;
int main() {
    cin >> n;
    while  (n --) {
        cin >> s;
        if (flag == true && s == "sweet" && n >= 1)
            l = true;
        if (s == "salty")
            flag = false;
        if (s == "sweet")
            flag = true;
    }
    if (l == false)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
