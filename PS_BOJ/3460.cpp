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

int T, N;

int main() { FAST
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i != 32; ++i)
            if (N & 1 << i) cout << i << " ";
        cout << endl;
    }
}
