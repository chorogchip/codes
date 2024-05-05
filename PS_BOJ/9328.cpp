#include<bits/stdc++.h>
using namespace std;


char d[128][128];
bool v[128][128];
bool has_key[26];
vector<pair<int,int>> doors[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m; cin.getline(d[1]+1, 128);
        for (int i = 1; i <= n; ++i)
            cin.getline(d[i] + 1, 128);
        for (int i = 0; i <= n + 1; ++i) d[i][0] = d[i][m+1] = '*';
        for (int i = 0; i <= m + 1; ++i) d[0][i] = d[n+1][i] = '*';
        string key_str; cin >> key_str;
        memset(has_key, 0, sizeof(has_key));
        for (int i = 0; i < 26; ++i) doors[i].clear();
        if (key_str[0] != '0') for (auto o : key_str) has_key[o - 'a'] = true;

        memset(v, 0, sizeof(v));
        queue<pair<int,int>> qu;
        for (int x = 1; x <= m; ++x) {
            if (d[1][x] != '*') qu.push({1, x});
            if (d[n][x] != '*') qu.push({n, x});
        }
        for (int y = 2; y < n; ++y) {
            if (d[y][1] != '*') qu.push({y, 1});
            if (d[y][m] != '*') qu.push({y, m});
        }


        {   /*
            for (int y = 0; y <= n+1; ++y) {
                for (int x = 0; x <= m+1; ++x) {
                    cout << d[y][x] << ' ';
                }
                cout << '\n';
            }    
            auto qqu = qu;
            while(!qqu.empty()) cout << qqu.front().first << ' ' << qqu.front().second << '/', qqu.pop(); cout << " asd\n";
        */}

        int res = 0;
        while (!qu.empty()) {
            auto [yy, xx] = qu.front(); qu.pop();
            if (v[yy][xx]) continue;
            v[yy][xx] = true;

            //cout << yy << ' ' << xx << '\n';

            char c = d[yy][xx];
            if (c == '*') continue;
            else if (c == '.') ;
            else if (c == '$') ++res;
            else if (c >= 'a') {
                int idx = c - 'a';
                has_key[idx] = true;
                for (auto o : doors[idx]) {
                    auto [yyy, xxx] = o;
                    qu.push({yyy-1, xxx});
                    qu.push({yyy+1, xxx});
                    qu.push({yyy, xxx-1});
                    qu.push({yyy, xxx+1});
                }
                doors[idx].clear();
            } else {
                int idx = c - 'A';
                if (!has_key[idx]) {
                    doors[idx].push_back({yy, xx});
                    continue;
                }
            }
            qu.push({yy-1, xx});
            qu.push({yy+1, xx});
            qu.push({yy, xx-1});
            qu.push({yy, xx+1});
        }
        cout << res << '\n';
    }
}