#include<bits/stdc++.h>
using namespace std;

signed char d[501'0000];

int main() {
    int n; cin >> n;
    string str;
    d[1] = 1;
    for (long long i = 1; i <= n; ++i) {
        if (d[i]) {
            str += 'B';
        } else {
            // prime
            for (long long j = i + i; j <= n; j += i) d[j] = 1;
            if (str.back() == 'B') str.back() = 'S', str += 'S';
            else str += 'S';
        }
    }
    int b = 0, s = 0;
    for (auto o : str) {
        if (o == 'B') ++b;
        else ++s;
    }
    cout << b << ' ' << s;
}