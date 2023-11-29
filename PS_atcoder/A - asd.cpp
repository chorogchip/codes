#include <bits/stdc++.h>

using namespace std;
int main() {
    int n; cin >> n;
    string str; cin >> str;
    int nn = (n + 1) >> 1;

    int t = 0, a = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'T') {
            ++t;
            if (t == nn) {
                cout << 'T';
                break;
            }
        } else {
            ++a;
            if (a == nn) {
                cout << 'A';
                break;
            }
        }
    }
}