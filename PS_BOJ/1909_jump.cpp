#include<bits/stdc++.h>
using namespace std;

int lgn(int i) {
    return 31 - __builtin_clz(i+1);
}
int lgg(int i) {
    return (1 << i) - 1;
}

map<pair<int,int>,int> m;

int solve(int x, int y) {
    if (x == 0 && y == 0) return 0;
    if (m.contains({x, y})) return m[{x, y}];
    int lgx = lgn(x);
    int lgoffx = lgg(lgx);
    int lgy = lgn(y);
    int lgoffy = lgg(lgy);
    int ans;
    if (lgy > lgx) ans = max(
        lgx + solve(x - lgoffx, lgoffy - 1 - lgoffx),
        lgy + solve(0, y - lgoffy));
    else ans = lgx + solve(x - lgoffx, y - lgoffx);
    m.insert({{x, y}, ans});
    return ans;
}

int solve2(int i, int step) {
    if (i == 0) return 0;
    for (int sum = 1, k = 1; sum <= i; k<<=1, sum+=k) {

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        cout << solve(x, y) << '\n';
    }
}