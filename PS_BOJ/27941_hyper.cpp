#include<bits/stdc++.h>
using namespace std;

int arr[2048];
int L[11], R[11];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int j = 0; j < 11; ++j) {
        int x; cin >> x;
        L[j] = x;
        arr[0] = 1;
    }
    for (int i = 1; i < 2047; ++i) {
        int res = 0;
        for (int j = 0; j < 11; ++j) {
            int x; cin >> x;
            if (L[j] != x) R[j] = x;
            res <<= 1;
            res += L[j] != x;
        }
        arr[res] = 1;
    }
    for (int i = 0; i < 2048; ++i) {
        if (!arr[i]) {
            for (int j = 0; j < 11; ++j) {
                cout << (i >> 10 - j & 1 ? R[j] : L[j]) << ' ';
            }
            cout << '\n';
            return 0;
        }
    }
}