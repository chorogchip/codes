#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int R;
char arr[1010101];

main() {
    scanf("%[^\n]", arr);
    for (char *p = arr; *p; ++p)
        if (*p >= 'A' && *(p+1) < 'A') ++R;
    printf("%d", R);
}

