#include<bits/stdc++.h>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define LL long long
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int N, Ds[500000], A, B, C, D, I[8001], MC = -1, M1, M2, MNC = 0;
double SUM;

MAIN { FAST
    cin >> N;
    foreach (i, N) cin >> Ds[i];
    sort(Ds, Ds + N);
    for (int i = 0; i != N; ++i) {
        SUM += Ds[i];
        I[Ds[i] + 4000]++;
    }
    for (int i = 0; i != 8001; ++i) {
        if (I[i] > MC) {
            M1 = M2 = i;
            MC = I[i];
            MNC = 1;
        } else if (I[i] == MC) {
            if (MNC == 0) {
                MNC++;
                M1 = i;
            } else if (MNC == 1) {
                MNC++;
                M2 = i;
            }
        }
    }
    A = round(SUM / N);
    B = Ds[N >> 1];
    C = M2 - 4000;
    D = Ds[N - 1] - Ds[0];
    cout << A << endl << B << endl << C << endl << D << endl;
}