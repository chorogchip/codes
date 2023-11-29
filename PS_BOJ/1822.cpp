#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
#define arrin(X, N) foreach (asd, (N)) cin >> (X)[asd];

int NA, NB, A[501010], B[501010], C;

MAIN { FAST
    cin >> NA >> NB;
    arrin(A, NA)
    arrin(B, NB)
    sort(A, A + NA);
    sort(B, B + NB);
    int x, lo, hi, md;
    vector<int> res;
    foreach (i, NA) {
        x = A[i];
        lo = 0;
        hi = NB - 1;
        while (lo < hi) {
            md = lo + hi >> 1;
            if (B[md] >= x) hi = md;
            else lo = md + 1;
        }
        if (B[lo] != x) ++C, res.push_back(x);
    }
    cout << C << endl;
    for (auto o : res) cout << o << " ";
}