#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<string,int> m;
    for (int i = 0; i < n; ++i) {
        string str; cin >> str;
        int sz = str.size();
        string str_n;
        for (int i = sz - 1; i >= 0; --i) {
            str_n += str[i];
            auto o = m.find(str_n);
            if (o != m.end()) o->second++;
            else m.insert({str_n, 1});
        }
    }
    int res = 0;
    for (auto o : m) {
        if (o.second & 1) res++;
    }
    cout << res;
}