#include<bits/stdc++.h>
using namespace std;

int d[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int sum = 0, M = 0;
    for (int i = 0; i < n; ++i) cin >> d[i];
    for (int i = 1; i < n-1; ++i) sum += d[i], M = max(M, d[i]);
    int res = sum + M;
    for (int psum = d[n-1], i = n-2; i > 0; --i) {
        int am = sum + d[n-1] + psum - d[i];
        res = max(res, am);
        psum += d[i];
    }
    for (int psum = d[0], i = 1; i < n-1; ++i) {
        int am = sum + d[0] + psum - d[i];
        res = max(res, am);
        psum += d[i];
    }
    cout << res;
}