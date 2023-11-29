#include<bits/stdc++.h>
using namespace std;

pair<int,int> inp[501010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x >> inp[i].first >> inp[i].second;
        inp[i].second = -inp[i].second; 
    }
    sort(inp, inp + n);
    vector<pair<int,int>> ii;
    ii.push_back({inp[0]});
    for (int i = 1; i < n; ++i) {
        if (inp[i].second != inp[i-1].second || inp[i].first != inp[i-1].first)
            ii.push_back({inp[i]});
    }

    vector<int> l;
    for (int i = 0; i < ii.size(); ++i) {
        int x = ii[i].second;
        if (i == 0 || l.back() <= x) l.push_back(x);
        else l[upper_bound(l.begin(), l.end(), x) - l.begin()] = x;
    }
    cout << l.size();
}