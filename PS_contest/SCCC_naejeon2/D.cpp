#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; unsigned a, b; cin >> n >> a >> b;
    if ((a | b) != b) {
        cout << "-1";
        return 0;
    }
    unsigned c = b & ~a;
    vector<pair<int,unsigned>> but;
    for (int i = 0; i < n; ++i) {
        unsigned x; cin >> x;
        if ((x | a) == a) continue;
        if ((x | b) != b) continue;
        but.push_back({i, x});
    }

}