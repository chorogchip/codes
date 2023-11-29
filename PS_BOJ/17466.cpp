#include<iostream>
#include<algorithm>

using namespace std;

#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main() { cin.sync_with_stdio(0); cin.tie(0);

long long n, p, mul;

MAIN
cin >> n >> p;
mul = 1L;
for (long long i = 2L; i <= n; ++i) {
    mul *= i;
    mul %= p;
}
cout << mul;
}