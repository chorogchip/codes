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

int N, R, M[] = { 500, 100, 50, 10, 5, 1 };

int main() { FAST
    cin >> N;
    N = 1000 - N;
    for (int i = 0; i != 6; ++i) {
        R += N / M[i];
        N %= M[i];
    }
    cout << R << endl;
}
