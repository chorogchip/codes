#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    string str; cin >> str;
    for (auto& c : str) {
        if (c != 'A' && c + k > 'Z') k -= 'Z' + 1 - c, c = 'A';
    }
    str.back() = (str.back() + k % 26 - 'A') % 26 + 'A';
    cout << str;
}