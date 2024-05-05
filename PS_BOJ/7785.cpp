#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    set<string, greater<string>> st;
    int n; cin >> n;
    while(n--) {
        string s1, s2; cin >> s1 >> s2;
        if (s2 == "enter") st.insert(s1);
        else st.erase(s1);
    }
    for (auto o : st) cout << o << '\n';
}