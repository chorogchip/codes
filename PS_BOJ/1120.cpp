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

string A, B;
int N = 9999;

int main() { FAST
    cin >> A >> B;
    int as = A.size(), bs = B.size();
    int gap = bs - as;
    for (int i = 0; i <= gap; ++i) {
        int c = 0;
        for (int k = 0; k != as; ++k) if (A[k] != B[i + k]) ++c;
        N = min(N, c);
    }
    cout << N << endl;
}
