#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<string>

using namespace std;

#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define LL long long
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

string A, B, C;
int a, b;
struct DD {
    int val;
    int prev;
    DD(): val(0), prev(0) {}
    DD(int a, int b): val(a), prev(b) {}
};
DD D[1001][1001];
MAIN { FAST
    cin >> A >> B;
    a = A.length();
    b = B.length();
    A = '#' + A;
    B = '#' + B;
    for (int i = 1; i != a; ++i) D[i][0] = D[0][i] = DD();
    for (int i = 1; i <= a; ++i)
        for (int j = 0; j <= b; ++j)
            if (A[i] == B[j]) D[i][j].val = D[i - 1][j - 1].val + 1, D[i][j].prev = 3;
            else if (D[i - 1][j].val > D[i][j - 1].val) D[i][j].val = D[i - 1][j].val, D[i][j].prev = 1;
            else D[i][j].val = D[i][j - 1].val, D[i][j].prev = 2;
    cout << D[a][b].val << endl;
    for (int i = a, j = b; D[i][j].val;) {
        switch (D[i][j].prev) {
            case 0: break;
            case 1: i--; continue;
            case 2: j--; continue;
            case 3: C += A[i--], j--; continue;
        }
        break;
    }
    for (int i = (int)C.length() - 1; i >= 0; --i) cout << C[i];
}