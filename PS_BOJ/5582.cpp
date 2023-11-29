#include<bits/stdc++.h>
using namespace std;

int dp[4096][4096];

int main() {
    string a, b; cin >> a >> b;
    int al = a.size(), bl = b.size();
    a = '#' + a;
    b = '#' + b;
    for (int i = 1; i <= al; ++i) {
        for (int j = 1; j <= bl; ++j) {
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[al][bl];
}