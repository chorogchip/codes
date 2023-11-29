#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

long long R, C;
int L;

long long mypow(int a, int r) {
    if (r == 0) return 1;
    if (r == 1) return a;
    if (r & 1) {
        long long rr = mypow(a, r >> 1) % 1234567891L;
        return (((rr * rr) % 1234567891L) * a) % 1234567891L;
    } else {
        long long rr = mypow(a, r >> 1) % 1234567891L;
        return (rr * rr) % 1234567891L;
    }
}

main() { 
    scanf("%d", &L);
    getchar();
    fore (i, L) {
        C = getchar() - 'a' + 1;
        R = (R + (C * (mypow(31, i) % 1234567891L)) % 1234567891L) % 1234567891L;
    }
    cout << R % 1234567891L;
}