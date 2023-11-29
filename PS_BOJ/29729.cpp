#include<bits/stdc++.h>
using namespace std;

int main() {
    int cap, n, m, sz = 0;
    cin >> cap >> n >> m;
    for (int i = 0; i < n + m; ++i) {
        int x; cin >> x;
        if (x == 1) {
            if (sz == cap)
                cap *= 2;
            ++sz;
        } else {
            --sz;
        }
    }
    cout << cap;
}