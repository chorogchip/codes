#include<bits/stdc++.h>
using namespace std;

int dp[10101][4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int cost = 0;
    for (int i = 2; i <= n+1; ++i) {
        int a; cin >> a;
        int cnt_3 = min(a, dp[i-1][2]);
        dp[i-1][2] -= cnt_3; dp[i][3] += cnt_3; a -= cnt_3;
        cost += 2 * cnt_3;
        int cnt_23 = min(a, min(dp[i-1][3], dp[i-2][1]));
        dp[i-1][3] -= cnt_23; dp[i-2][1] -= cnt_23;
        dp[i-1][2] += cnt_23; dp[i][3] += cnt_23; a -= cnt_23;
        cost += 2 * cnt_23;
        int cnt_2 = min(a, dp[i-1][1]);
        dp[i-1][1] -= cnt_2; dp[i][2] += cnt_2; a -= cnt_2;
        cost += 2 * cnt_2;
        dp[i][1] += a;
        cost += 3 * a;
    }
    cout << cost;
}