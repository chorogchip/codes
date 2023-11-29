#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; string str; cin >> n >> str;
        vector<int> ans;
        int color = 0;
        int way = 0;
        int level = 0;
        if (n & 1) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (way == 0) {
                ++color;
                if (str[i] == '(') way = 1, level = 1;
                else way = 2, level = -1;
                ans.push_back(color);
            } else if (way == 1) {
                if (str[i] == '(') {
                    ++level;
                    ans.push_back(color);
                } else {
                    --level;
                    if (level < 0) {
                        --i;
                        level = 0;
                        way = 0;
                    }
                    else ans.push_back(color);
                }
            } else {
                if (str[i] == ')') {
                    --level;
                    ans.push_back(color);
                } else {
                    ++level;
                    if (level > 0) {
                        --i;
                        level = 0;
                        way = 0;
                    }
                    else ans.push_back(color);
                }
            }
        }
        if (level != 0) {
            cout << -1 << '\n';
            continue;
        }
        cout << min(2, color) << '\n';
        for (auto o : ans) cout << ((o & 1) ? 1 : 2) << ' ';
        cout << '\n';
    }
}
