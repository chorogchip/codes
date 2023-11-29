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

int A, B, C, D;

int main() { FAST
    cin >> A >> B >> C >> D;
    A = D / A + (bool)(D % A);
    B = B / C + (bool)(B % C);
    if (A < B) cout << "PLAYER A\n";
    else if (A > B) cout << "PLAYER B\n";
    else cout << "DRAW\n";
}
