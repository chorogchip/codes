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

int N, C, X;

int main() { FAST
    cin >> N;
    fore (i, 5) if (cin >> X, X == N) ++C;
    cout << C << endl;
}
