#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> a(n);
    for (auto& o : a) cin >> o;
    sort(a.begin(), a.end());
    ll cur = a[0], big = a[0], cnt = 1, big_cnt = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == cur) ++cnt;
        else {
            if (cnt > big_cnt) big_cnt = cnt, big = cur;
            cnt = 1;
            cur = a[i];
        }
    }
    if (cnt > big_cnt) big_cnt = cnt, big = cur;
    cout << big;
}