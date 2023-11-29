
#include<bits/stdc++.h>
using namespace std;
std::queue<int> qu;

int main() {
    int n, l, i = 0, al = 0, r = 0; cin >> n >> l;
    for (; i < l; ++i) {
        int x; cin >> x; al += x;
        if (al >= 129 && al <= 138) ++r;
        qu.push(x);
    }
    for (; i < n; ++i) {
        int x; cin >> x; al += x;
        al -= qu.front(); qu.pop();
        if (al >= 129 && al <= 138) ++r;
        qu.push(x);
    }
    cout << r;
}