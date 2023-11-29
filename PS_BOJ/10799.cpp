#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

char C[101001], *p = C;

MAIN {
    int res = 0, lev = 0;
    gets(C);
    do if (*p == '(')
        if (*(p + 1) == ')') p++, res += lev;
        else lev++;
    else lev--, res++;
    while (*++p != '\0');
    cout << res;
}