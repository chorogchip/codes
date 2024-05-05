#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int sz = s.size();
    unordered_set<string> st;
    for (int i = 0; i < sz; ++i) {
        string s2 = "";
        for (int j = i; j < sz; ++j) {
            s2 += s[j];
            st.insert(s2);
        }
    }
    cout << st.size();
}