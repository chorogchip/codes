#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, X, H[101010], I = 0;

inline void push() {
    H[++I] = X;
    int temp;
    for (int i = I; i > 1 && H[i] < H[i>>1];) {
        temp = H[i];
        H[i] = H[i>>1];
        H[i>>=1] = temp;
    }
}

inline void pop() {
    H[1] = H[I--];
    int temp, j;
    for (int i = 1; (j = i << 1) <= I;) {
        if (j+1 <= I && H[j+1] < H[j]) j += 1;
        if (H[j] < H[i]) {
            temp = H[i];
            H[i] = H[j];
            H[i = j] = temp;
        } else break;
    }
}

main() { FAST
    cin >> N;
    while (N--) {
        cin >> X;
        if (X == 0)
            if (I == 0) cout << 0 << endl;
            else cout << H[1] << endl, pop();
        else push();
    }
}

