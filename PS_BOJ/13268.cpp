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

int N, R, D[] = { 1, 1, 1, 2, 2, 1, 1, 2, 3, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1 },
D2[] =          { 0, 1, 0, 1, 2, 1, 0, 1, 2, 3, 2, 1, 0, 1, 2, 3, 4, 3, 2, 1 };

int main() { FAST
    cin >> N; N %= 100;
    if (N % 5 == 0) { cout << D2[N/5] << endl; return 0; }
    N /= 5; cout << D[N] << endl;
}
