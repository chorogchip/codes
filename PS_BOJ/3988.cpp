#include <bits/stdc++.h>
using namespace std;

int d[1010101];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, nn; cin >> n >> k; nn = n - k;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    sort(d + 1, d + 1 + n);
    int i, m = 1010101010;
    deque<pair<int,int>> dq; 
    for (i = 2; i < nn; ++i) {
        int x = d[i] - d[i-1];
        while (!dq.empty() && dq.back().first >= x) dq.pop_back();
        dq.push_back({x, i});
    }
    for (; i <= n; ++i) {
        int x = d[i] - d[i-1];
        while (!dq.empty() && dq.back().first >= x) dq.pop_back();
        dq.push_back({x, i});
        if (dq.front().second <= i - nn + 1) dq.pop_front();
        m = min(m, dq.front().first + d[i] - d[i-nn+1]);
    }
    cout << m;
}