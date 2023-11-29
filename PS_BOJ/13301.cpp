#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fib[100];

int main() {
    int n; cin >> n;
    switch(n) {
        case 1: cout << 4; exit(0);
        case 2: cout << 6; exit(0);
        case 3: cout << 10; exit(0);
    }
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) fib[i] = fib[i-1] + fib[i-2];
    cout << fib[n] * 3 + fib[n-1] * 2 + fib[n-2] * 2 + fib[n-3];
}