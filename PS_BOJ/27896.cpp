#include <bits/stdc++.h>
using namespace std;

int x[201010];

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    priority_queue<int> qu;
    using ll = long long;
    ll sum = 0;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        qu.push(x[i]);
        sum += x[i];
        if (sum  >= m) {
            sum -= qu.top() << 1; qu.pop();
            ++res;
        }
    }
    cout << res;
}
