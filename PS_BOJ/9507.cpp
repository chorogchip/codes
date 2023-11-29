#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[70];

ll fib(int n) {
    if (n < 2) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    if (dp[n]) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2) + fib(n-3) + fib(n-4);
}

int main() {
    int t; cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        int n; cin >> n;
        cout << fib(n) << '\n';
    }
}