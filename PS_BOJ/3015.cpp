#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<pair<int,int>> v;
    ll res = 0;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        while(!v.empty()) {
            auto& bck = v.back();
            if (bck.first < x) {
                res += bck.second;
                v.pop_back();
            } else if (bck.first == x) {
                res += bck.second;
                if (v.size() > 1) res++;
                break;
            } else {
                res++;
                break;
            }
        }
        if (!v.empty() && v.back().first == x)
            v.back().second++;
        else v.push_back({x, 1});

    }
    cout << res;
}