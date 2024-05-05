#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s[16];
    for (int i = 0; i < 5; ++i) {
        string ss; cin >> ss;
        int sz = ss.size();
        for (int j = 0; j < sz; ++j) s[j] += ss[j];
    }
    for (int i = 0; i < 16; ++i) cout << s[i];
}