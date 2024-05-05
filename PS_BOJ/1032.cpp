#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string str; cin >> str;
    for (int i = 1; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < str.size(); ++j)
            if (str[j] != s[j]) str[j] = '?';
    }
    cout << str;
}