#include <bits/stdc++.h>
using namespace std;

int fib[32];

int main() {
    int d, k; cin >> d >> k;
    fib[1] = 1;
    for (int i = 2; i <= d; ++i) fib[i] = fib[i-1] + fib[i-2];
    int a = fib[d-2];
    int b = fib[d-1];
    for (int j = k / b; j > 0; --j) {
        int rem = k - b * j;
        if (rem % a == 0 && rem != 0 && rem / a <= j) {
            cout << rem / a << '\n' << j;
            exit(0);
        }
    }
}