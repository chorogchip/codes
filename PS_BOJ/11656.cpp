#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str; cin >> str;
    vector<string> v;
    for (int i = str.size() - 1; i >= 0; --i) {
        string str2;
        for (int j = i; j < str.size(); ++j) str2 += str[j];
        v.push_back(str2);
    }
    sort(v.begin(), v.end());
    for (auto o : v) cout << o << '\n';
}