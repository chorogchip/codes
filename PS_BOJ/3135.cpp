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

int A, B, N, X, M;

int main() { FAST
    cin >> A >> B >> N;
    M = abs(A - B);
    fore (i, N) {
        cin >> X;
        M = min(M, abs(B - X)+1);
    }
    cout << M << endl;
    
}
