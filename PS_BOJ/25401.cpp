#include<bits/stdc++.h>
using namespace std;

int d[512];

int gcdd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        map<pair<int,int>,int> mp;
        for (int j = 1; j <= n; ++j) if (i != j) {
            int gap_x = j - i;
            int gap_y = d[j] - d[i];
            int gcgcd = gcdd(abs(gap_x), abs(gap_y));
            gap_x /= gcgcd;
            gap_y /= gcgcd;
            if (mp.contains({gap_x, gap_y})) mp[{gap_x, gap_y}]++;
            else mp.insert({{gap_x, gap_y}, 1});
        }
        for (auto& [p, cnt] : mp) {
            res = max(res, cnt);
        }
    }
    cout << n - 1 - res;
}