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

int n, arr[500001], *p = arr, *arrn;

int getPrime() {
    arr[0] = 2;
    p++;
    int num = 3;
    arrn = arr + n;
    while (p != arrn) {
        for (int* p2 = arr; *p2 * *p2 <= num; ++p2) if (!(num % *p2)) goto ASD;
        *p++ = num;
        ASD: num++;
    }
    return *--p;
}

MAIN { FAST
    cin >> n;
    cout << getPrime();
}