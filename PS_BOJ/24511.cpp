#include<bits/stdc++.h>
using namespace std;

bool b[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    deque<int> qu;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; b[i] = x;
    }
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; if (!b[i]) qu.push_front(x);
    }
    int m; cin >> m;
    while(m--) {
        int x; cin >> x;
        qu.push_back(x);
        auto o = qu.front(); qu.pop_front();
        cout << o << ' ';
    }
}