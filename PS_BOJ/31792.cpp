#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    map<int,int> mp;
    int q; cin >> q;
    while(q--) {
        int a; cin >> a;
        if (a == 1) {
            int s; cin >> s;
            if (mp.contains(s)) mp[s]++;
            else mp.insert({s, 1});
        } else if (a == 2) {
            int s; cin >> s;
            if (mp.contains(s) && --mp[s] == 0) mp.erase(s);
        } else {
            int cnt = 0;
            auto it = mp.begin();
            while (it != mp.end()) {
                ++cnt;
                int num = it->first;
                it = mp.lower_bound(num*2);
            }
            cout << cnt << '\n';
        }
    }
}