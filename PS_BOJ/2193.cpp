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

unsigned long long N, F[100], S;

int main() {
    cin >> N;
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= N; ++i)
        F[i] = (S += F[i-2]) + 1;
    cout << F[N] << endl;
}
