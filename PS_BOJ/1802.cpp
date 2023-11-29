#include<bits/stdc++.h>
using namespace std;

bool asdf(string s) {
    int sz = s.size();
    if (sz == 1) return true;
    int md = sz >> 1;
    for (int i = 0; i < md; ++i)
        if (s[i] == s[sz - i - 1]) return false;
    return asdf(s.substr(0, md)) && asdf(s.substr(md + 1, md));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << (asdf(s) ? "YES\n" : "NO\n");
    }
}