#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;

#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define LL long long
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);

unsigned int n;
char isprime[50000001];

MAIN { FAST
    cin >> n;
    n++;
    unsigned int res;
    unsigned int temp;
    unsigned long long num;
    unsigned int i;

    num = 2;
    while (num < n) num *= 2;
    num /= 2;
    res = num;

    for (i = 3; (temp = i * i) < n; i += 2) if (!isprime[i >> 1]) {
        num = i;
        while (num < n) num *= i;
        num /= i;
        res *= num;
        for (unsigned int j = temp; j < n; j += i + i)
            isprime[j >> 1] = 1;
    }
    for (; i < n; i += 2)
        if (!isprime[i >> 1]) res *= i;

    cout << res;
}