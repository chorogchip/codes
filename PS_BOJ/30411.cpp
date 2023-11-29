#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<pair<int,int>> ans;
    ans.reserve(k);
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; j += 2) {
            ans.push_back({i, i - j});
            if (ans.size() == k) goto END;
        }
    }
    cout << "NO";
    exit(0);
    END: cout << "YES\n";
    for(auto o : ans) cout << o.first << ' ' << o.second << '\n';
}