#include<bits/stdc++.h>
using namespace std;

int par[401010];
int t[401010];
pair<int,pair<int,int>> query[401010];

int find(int v) {
    if (par[v] == v) return v;
    else return par[v] = find(par[v]);
}

void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    par[aa] = bb;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        cin >> t[i];
        par[i] = i;
    } t[1] = 1; par[1] = 1;
    for (int i = 0; i < n + q - 1; ++i) {
        cin >> query[i].first;
        if (!query[i].first) cin >> query[i].second.first;
        else cin >> query[i].second.first >> query[i].second.second;
    }
    vector<const char*> vec;
    vec.reserve(q);
    for (int i = n + q - 2; i >= 0; --i) {
        if (!query[i].first) merge(query[i].second.first, t[query[i].second.first]);
        else  vec.push_back(find(query[i].second.first) == find(query[i].second.second) ? "YES\n" : "NO\n");
    }
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) cout << *it;
}