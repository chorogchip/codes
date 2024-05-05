#include<bits/stdc++.h>
using namespace std;

int from[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for (auto &[l, r] : v) cin >> l >> r;
    sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>&b)->bool{
        int as = a.second - a.first;
        int bs = b.second - b.first;
        if (as != bs) return as < bs;
        return a.first < b.first;
    });
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();
    map<pair<int,int>,pair<int,int>> st;
    int max_cnt = 0, max_num = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 1; from[i] = -1;
        auto [l, r] = v[i];
        auto it = st.lower_bound({l, 0});
        while (it != st.end() && it->first.second <= r) {
            if (cnt < 1 + it->second.second)
                cnt = 1 + it->second.second, from[i] = it->second.first;
            it = st.erase(it);
        }
        if (max_cnt < cnt)
            max_cnt = cnt, max_num = i;
        st.insert({{l, r}, {i, cnt}});
    }
    cout << max_cnt << '\n';
    do cout << v[max_num].first << ' ' << v[max_num].second << '\n';
    while((max_num = from[max_num]) != -1);
}