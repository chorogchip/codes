#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll val[1010101];
ll sum[1010101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    const int MX = 1'000'000;

    for (int i = 1; i <= 1000; ++i) {
        val[i * i] += i;
        for (ll j = i + 1; j <= MX/i; j++)
            val[j*i] += i + j;
    }

    for (int i = 1; i <= MX; ++i) sum[i] = sum[i-1] + val[i];
    while(t--) {
        int n; cin >> n;
        cout << sum[n] << '\n';
    }
}