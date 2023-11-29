#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

int cnt[401010], cntt[401010], arr[201010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        memset(cnt, 0, 4 * (2 * n + 1));
        memset(cntt, 0, 4 * (2 * n + 1));
        {
            int persist = 1;
            cin >> arr[0];
            for (int i = 1; i < n; ++i) {
                cin >> arr[i];
                if (arr[i] != arr[i-1]) {
                    cnt[arr[i-1]] = max(cnt[arr[i-1]], persist);
                    persist = 1;
                } else ++persist;
            }
            cnt[arr[n-1]] = max(cnt[arr[n-1]], persist);
        }
        {
            int persist = 1;
            cin >> arr[0];
            for (int i = 1; i < n; ++i) {
                cin >> arr[i];
                if (arr[i] != arr[i-1]) {
                    cntt[arr[i-1]] = max(cntt[arr[i-1]], persist);
                    persist = 1;
                } else ++persist;
            }
            cntt[arr[n-1]] = max(cntt[arr[n-1]], persist);
        }
        int res = 0;
        for (int i = 1; i <= 2 * n; ++i) {
            res = max(res, cnt[i] + cntt[i]);
        }
        cout << res << '\n';
    }
}
