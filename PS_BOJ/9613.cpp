#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int arr[128];

ll gcdd(ll a, ll b) {
    if (b == 0) return a;
    else return gcdd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            for (int j = 0; j < i; ++j) res += gcdd(arr[i], arr[j]);
        }
        cout << res << '\n';
    }
}