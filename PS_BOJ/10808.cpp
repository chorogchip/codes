#include<bits/stdc++.h>
using namespace std;

int c[128];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    for (auto o : s) c[o]++;
    for (int i = 'a'; i <= 'z'; ++i) cout << c[i] << ' ';
}