#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    set<string> st;
    int cnt = 0;
    while(n--) {
        string str; cin >> str;
        if (str == "ENTER") st.clear();
        else if (!st.contains(str)) ++cnt, st.insert(str);
    }
    cout << cnt;
}