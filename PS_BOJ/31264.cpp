#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll arr[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; ll a; cin >> n >> m >> a;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);
    ll lo = arr[0], hi = arr[n-1];
    while (lo < hi) {
        ll md = lo + hi >> 1;
        ll score = md;
        for (int mm = 0; mm < m; ++mm)
            score += *(upper_bound(arr, arr + n, score)-1);
        if (score - md < a) lo = md + 1;
        else hi = md;
    }
    cout << lo;
}