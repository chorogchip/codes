#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, res = 0; cin >> n;
    while(n--) {
        string s; cin >> s;
        int sz = s.size();
        if (s.size() > 10) continue;
        for (int i = 0; i < sz; ++i) if (s[i] < '0' || s[i] > '9') goto E;
        continue;
        E:
        int a = 0, b = 0;
        for (int i = 0; i < sz; ++i) if (s[i] <= 'z') {
            if (s[i] >= 'a') ++a;
            else if (s[i] >= 'A') ++b;
        }
        if (a < b) continue;
        cout <<s << '\n';    }
}