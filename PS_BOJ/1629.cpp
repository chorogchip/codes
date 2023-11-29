#include<iostream>
#include<algorithm>

using namespace std;

#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define LL long long
#define MAIN int main() { cin.sync_with_stdio(0); cin.tie(0);

LL a, b, c;

LL pow(LL n, LL p) {
    LL res = 1;
    do {
        if (p & 1) (res *= n) %= c;
        (n *= n) %= c;
    }
    while (p >>= 1);
    return res;
}

MAIN
cin >> a >> b >> c;
cout << pow(a, b);
}
