#include<bits/stdc++.h>
using namespace std;

int main() {
    int k; cin >> k;
    int a = 1, b = 0;
    for (int i = 0; i < k; ++i) {
        int tmpb = b;
        b += a;
        a = tmpb;
    }
    cout << a << ' ' << b;
}