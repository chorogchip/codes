#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b; cin >> a >> b;
    set<int> st;
    for (int i = 0; i < a; ++i) { int x; cin >> x; st.insert(x); }
    for (int i = 0; i < b; ++i) { int x; cin >> x; st.insert(x); }
    cout << 2 * st.size() - a - b;
}