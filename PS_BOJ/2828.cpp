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

int N, M, J, X, P, R;

int main() { FAST
    P = 1;
    cin >> N >> M >> J;
    while (J--) {
        cin >> X;
        if (P > X) R += P - X, P = X;
        else if (P + M <= X) R += X - (P + M - 1), P = X - M + 1; 
    }
    cout << R << endl;
}
