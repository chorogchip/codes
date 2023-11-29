#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str; cin >> str;
    stack<int> st;
    vector<pair<int,int>> par;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') st.push(i);
        else if (str[i] == ')') par.push_back({st.top(), i}), st.pop(); 
    }

    int exp = 1 << par.size();
    vector<string> ans;
    for (int i = 1; i < exp; ++i) {
        string st = str;
        for (int j = 0; j < par.size(); ++j) {
            if (1 << j & i) st[par[j].first] = st[par[j].second] = '.';
        }
        string res;
        res.reserve(st.size());
        for (auto o : st) if (o != '.') res.push_back(o);
        ans.push_back(res);
    }

    sort(ans.begin(), ans.end());
    cout << ans[0] << '\n';
    for (int i = 1; i < ans.size(); ++i) {
        if (ans[i] != ans[i-1]) cout << ans[i] << '\n';
    }
}