#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    set<string> st;
    st.insert("ChongChong");
    while(n--) {
        string a, b; cin >> a >> b;
        if (st.contains(a) || st.contains(b))
            st.insert(a), st.insert(b);
    }
    cout << st.size();
}