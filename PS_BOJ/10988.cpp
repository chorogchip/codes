#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] != s[s.size() - i - 1]) goto NO;
    cout << 1; exit(0);
    NO: cout << 0;
}