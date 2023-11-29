#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int F[1500001];

int main() { FAST
    unsigned long long N;
    cin >> N;
    F[1] = 1;
    for (int i = 2; i <= 1500000; ++i) F[i] = (F[i-1] + F[i-2]) % 1000000;
    N %= 1500000;
    cout << F[N] << endl;
}
