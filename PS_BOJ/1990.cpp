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

int a, b;

inline bool isPrime(int n) {
    if ((n & 1) == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

inline void ifprimeandprt(int n) {
    if (n >= a && isPrime(n)) cout << n << endl;
}

inline int pow10(int num, int gen) {
    switch(num) {
        case 1:
            switch(gen) {
                case 0: return 1;
            }
        case 2:
            switch(gen) {
                case 0: return 101;
                case 1: return 10;
            }
        case 3:
            switch(gen) {
                case 0: return 10001;
                case 1: return 1010;
                case 2: return 100;
            }
        case 4:
            switch(gen) {
                case 0: return 1000001;
                case 1: return 100010;
                case 2: return 10100;
                case 3: return 1000;
            }
    }
    return 1;
}

inline bool getP(int num, int total, int gened) {
    if (total == gened) if (num > b) return true; else { ifprimeandprt(num); return false; }
    for (int i = 0; i != 10; ++i) {
        if (i == 0 && gened == 0) continue;
        if (getP(num + i * pow10(total, gened), total, gened + 1)) return true;
    }
    return false;
}

MAIN { FAST
    cin >> a >> b;
    if (getP(0, 1, 0)) goto ASD;
    if (a <= 11 && b >= 11) cout << 11 << endl;
    if (getP(0, 2, 0)) goto ASD;
    if (getP(0, 3, 0)) goto ASD;
    if (getP(0, 4, 0)) goto ASD;
    ASD: cout << -1;
}