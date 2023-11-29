#include<bits/stdc++.h>
using namespace std;

int a[101010];

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

vector<int> res;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        int n; cin >> n;
        res.clear();
        a[0] = a[n+1] = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int nn = (n+1)/2;
        for (int i = 1; i <= nn; ++i) {
            int gap = abs(a[i] - a[n-i+1]);
            if (gap != 0) res.push_back(gap);
        }
        int sz = res.size();
        if (sz == 0) cout << 0 << '\n';
        else {
            int result = res[0];
            for (int i = 1; i < sz; ++i) {
                result = gcd(result, res[i]);
            }
            cout << result << '\n';
        }
    }
}