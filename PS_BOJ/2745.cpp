#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; int n; cin >> s >> n;
    int num = 0;
    for (int i = 0; i < s.size(); ++i) {
        int c = s[i];
        if (c >= 'A') c = c - 'A' + 10;
        else c = c - '0';
        num = num * n + c;
    }
    cout << num;
}