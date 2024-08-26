#include <bits/stdc++.h>

using namespace std;
stack<char> s;
int num;
char trans(char a) {
    if (a == ')') return '(';
    if (a == ']') return '[';
    if (a == '}') return '{';
    return '\0';
}
int main() {
    cin >> num;
    string p;
    //getline(cin, p);//¶ÁÈ¡Ä©Î²µÄÖ¸Õë
    //getchar();
    while (num--) {
        while (!s.empty())s.pop();
        getline(cin, p);
        for (int i = 0; i < p.size(); i++) {
            if (s.empty()) {
                s.push(p[i]);
                continue;
            }
            if (trans(p[i]) == s.top())s.pop();
            else s.push(p[i]);
        }
        if (s.empty())printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
