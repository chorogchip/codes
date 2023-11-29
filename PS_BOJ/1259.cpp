#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);

int I;
char arr[6];

MAIN { FAST
    ST:
    I = 0;
    while((arr[I++] = getchar()) != '\n');
    if (arr[0] == '0') return 0;
    for (int i = 0; i < I - 1; ++i)
        if (arr[i] != arr[I - i - 2]) {
            cout << "no\n";
            goto ST;
        }
    cout << "yes\n";
    goto ST;
}