#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;

ll a();
ll b();
ll c();
ll e() {
    cout << 0;
    exit(0);
    return 0;
}
char g() {
    static int i = 0;
    if (i < s.size()) return s[i++];
    else return -1;
}

ll a() {
    char ch;
    ll res = 0;
    while ((ch = g()), ch != -1) {
        if (ch == '(') res += b();
        else if (ch == '[') res += c();
        else e();
    }
    return res;
}

ll b() {
    char ch;
    ll res = 0;
    while ((ch = g()), ch != -1) {
        if (ch == '(') res += b();
        else if (ch == '[') res += c();
        else if (ch == ')') return res == 0 ? 2 : 2 * res;
        else e();
    }
    return e();
}

ll c() {
    char ch;
    ll res = 0;
    while ((ch = g()), ch != -1) {
        if (ch == '(') res += b();
        else if (ch == '[') res += c();
        else if (ch == ']') return res == 0 ? 3 : 3 * res;
        else e();
    }
    return e();
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    cout << a();
}