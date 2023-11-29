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

int N;
char C[30], C3[500], *p = C3;
const char *C2 = "1 2 3 4 5 1 2 3 4 5\n";

inline void a(int n) {
    if (n < 10) *p++ = n + '0', *p++ = '\n';
    else if (n < 100) *p++ = n/10 + '0', *p++ = n%10 + '0', *p++ = '\n';
    else *p++ = '1', *p++ = '0', *p++ = '0', *p++ = '\n';
}

int main() {
    scanf("%d", &N); getchar();
    for (int i = 1; i <= N; ++i) {
        fread(C, 1, 20, stdin);
        if (strcmp(C, C2) == 0) a(i);
    }
    fwrite(C3, 1, p - C3, stdout);
}
