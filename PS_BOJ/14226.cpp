#include<bits/stdc++.h>
using namespace std;

int ans[1024][1024];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int s; cin >> s;
    queue<pair<int,int>> qu;
    qu.push({1,0});
    int time = 1;
    while(!qu.empty()) {
        int sz = qu.size();
        for (int i = 0; i < sz; ++i) {
            auto o = qu.front(); qu.pop();
            if (ans[o.first][o.second]) continue;
            ans[o.first][o.second] = time;
            if (o.first != o.second && !ans[o.first][o.first])
                qu.push({o.first,o.first});
            if (o.first>1 && !ans[o.first-1][o.second])
                qu.push({o.first-1,o.second});
            o.first+=o.second;
            if (o.first<1024 && !ans[o.first][o.second])
                qu.push({o.first,o.second});
        }
        ++time;
    }
    int res = 1024;
    for (int i = 0; i < 1024; ++i) if (ans[s][i]) res = min(res, ans[s][i]);
    cout << res-1;
}