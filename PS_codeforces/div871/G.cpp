#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

ll sum_(ll r) {
    if (r < 1) return 0;
    return r * (r + 1) * (2 * r + 1) / 6;
}

ll sum(ll col, ll maxofs) {
    if (maxofs < 0) return 0;
    int st = (col * (col + 1) >> 1) + 1;
    return sum_(st + maxofs) - sum_(st - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        int max_row = 0;
        int r;
        while (1) {
            max_row++;
            int st = (max_row * (max_row + 1) >> 1) + 1;
            if (st > n) {
                --max_row;
                break;
            }
            r = n - st;
        }
        ll res = 0;
        int l = r - 1;
        for (int i = max_row; i >= 0; --i) {
            res += sum(i, min(r, i));
            res -= sum(i, l);
            --l;
        }
        cout << res << '\n';
    }
}
