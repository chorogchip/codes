#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    set<string> st;
    while(n--) {
        string s; cin >> s;
        st.insert(s);
    }
    int cnt = 0;
    while(m--) {
        string s; cin >> s;
        if (st.contains(s))++cnt;
    }
    cout << cnt;
}