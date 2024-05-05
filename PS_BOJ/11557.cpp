#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while(n--) {
        int k; cin >> k;
        map<int, string> m;
        for (int i = 0; i < k; ++i) {
            string s; int am; cin >> s >> am;
            m.insert({am, s});
        }
        cout << m.rbegin()->second << '\n';
    }
}