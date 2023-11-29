#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if (n & 1) {
        cout << 0;
        exit(0);
    }
    int a = 0, b = 0, c = 1;
    for (int i = 2; i < n; i += 2) {
        a += c;
        b += c;
        c += a + b;
    }
    cout << a + b + c * 3;
}