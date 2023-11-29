#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define LL long long
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int A, B;
long double A0, B0, A1, B1, AG[18], BG[18];

MAIN { FAST
    cin >> A >> B;
    A1 = A / 100.0L;
    B1 = B / 100.0L;
    A0 = 1.0L - A1;
    B0 = 1.0L - B1;
    AG[0] = BG[0] = 1.0;
    for (int i = 1; i <= 18; ++i) {
        for (int j = i; j > 0; --j) {
            AG[j] = AG[j - 1] * A1 + AG[j] * A0;
            BG[j] = BG[j - 1] * B1 + BG[j] * B0;
        }
        AG[0] = AG[0] * A0;
        BG[0] = BG[0] * B0;
    }
    
    A0 = 0.0L;
    B0 = 0.0L;
    A0 += AG[2] += AG[3] += AG[5] += AG[7] += AG[11] += AG[13] += AG[17];
    B0 += BG[2] += BG[3] += BG[5] += BG[7] += BG[11] += BG[13] += BG[17];
    cout << 1.0L - (1.0L - A0) * (1.0L - B0);
}