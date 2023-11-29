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


int n, x, soinsu[5000001] = {0,}, *p = soinsu;

inline void sol() {
    for (int i = 2; i <= 5000000; ++i) if (!soinsu[i]) {
        for (int j = i + i; j <= 5000000; j += i) if (!soinsu[j]) soinsu[j] = i;
        soinsu[i] = i;
    }
}

MAIN { FAST
    cin >> n;
    sol();
    foreach(i, n) {
        cin >> x;
        while (x > 1) {
            int num = soinsu[x];
            printf("%d ", num);
            x /= num;
        }
        putchar('\n');
    }
}