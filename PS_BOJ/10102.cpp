#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'A') ++a; else ++b;
    if (a == b) cout << "Tie";
    else if (a > b) cout << "A"; else cout << "B";
}