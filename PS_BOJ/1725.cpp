#include <bits/stdc++.h>
using namespace std;

int d[101010], l[101010], r[101010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    stack<pair<int,int>> ls, rs;
    for (int i = 1; i <= n; ++i) {
        while (!ls.empty() && ls.top().first >= d[i]) ls.pop();
        while (!rs.empty() && rs.top().first > d[i]) {
            r[rs.top().second] = i;
            rs.pop();
        }
        l[i] = ls.empty() ? 0 : ls.top().second;
        ls.push({d[i], i});
        rs.push({d[i], i});
    }
    while (!rs.empty()) {
        r[rs.top().second] = n + 1;
        rs.pop();
    }
    int m = 0;
    for (int i = 1; i <= n; ++i) m = max(m, d[i] * (r[i] - l[i] - 1));
    cout << m;
}