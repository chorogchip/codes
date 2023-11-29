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

int N, K, D[1010];

int main() { FAST
    cin >> N >> K;
    for (int i = 2; i <= N; ++i) if (!D[i])
        for (int j = i; j <= N; j += i) if (!D[j]) {
            D[j] = 1;
            if (!--K) { cout << j << endl; return 0; }
        }
}
