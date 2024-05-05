#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[10101];
int cnt[10101];
int times[10101];
int ran_cnt[10101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({b, c});
        cnt[b]++;
    }
    vector<int> vv;
    for (int i = 1; i <= n; ++i) if (!cnt[i]) vv.push_back(i);
    int res = 0, res_cnt = 0;
    while(!vv.empty()) {
        auto o = vv.back(); vv.pop_back();
        if (res < times[o])
            res = times[o], res_cnt = ran_cnt[o];
        for (auto oo : v[o]) {
            cnt[oo.first]--;
            if (times[oo.first] < times[o] + oo.second)
                times[oo.first] = times[o] + oo.second, ran_cnt[oo.first] = ran_cnt[o] + 1;
            if (!cnt[oo.first]) vv.push_back(oo.first);
        }
    }
    cout << res << '\n' << res_cnt;
}