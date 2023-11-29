#include<bits/stdc++.h>
using namespace std;

vector<int> fib[2];

int main() {
    int n; cin >> n;
    fib[0].push_back(0);
    fib[1].push_back(1);
    for (int i = 2; i <= n; ++i) {
        int carry = 0;
        int sz = fib[i&1].size();
        for (int j = 0; j < sz; ++j) {
            fib[i&1][j] += fib[i&1^1][j] + carry;
            carry = fib[i&1][j] / 10;
            fib[i&1][j] %= 10;
        }
        if (carry) {
            fib[i&1].push_back(carry);
            fib[i&1^1].push_back(0);
        }
    }
    auto& res = fib[n&1];
    for (int i = res.size() - 1; i >= 0; --i) cout << res[i];
}