#include<bits/stdc++.h>
using namespace std;

string str[64];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> str[i];
    sort(str, str + n, [](const string& a, const string& b) -> bool {
        if (a.size() != b.size()) return a.size() < b.size();
        int aa = 0, bb = 0;
        for (auto o : a) if (o >= '0' && o <= '9') aa += o - '0';
        for (auto o : b) if (o >= '0' && o <= '9') bb += o - '0';
        if (aa != bb) return aa < bb;
        return a < b;
    });
    for (int i = 0; i < n; ++i) cout << str[i] << '\n';
}