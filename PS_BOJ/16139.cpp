#include<bits/stdc++.h>
using namespace std;

int dp[201010][128];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str; cin >> str; str = "#" + str;
    for (int i = 0; i < str.size(); ++i) dp[i][str[i]]++;
    for (int i = 1; i < str.size(); ++i)
        for (int j = 0; j < 128; ++j) dp[i][j] += dp[i-1][j];
    int m; cin >> m;
    while(m--) {
        char c; int l, r; cin >> c >> l >> r;
        cout << dp[r+1][c] - dp[l][c] << '\n';
    }
}