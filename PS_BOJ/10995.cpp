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
char arr[100 * 100 * 3], *p = arr;

int main() {
    scanf("%d", &N);
    for (int i = 0; i != N; ++i) {
        if (i & 1) *p++ = ' ';
        for (int j = 1; j != N << 1; ++j)
            if (j & 1) *p++ = '*';
            else *p++ = ' ';
        *p++ = '\n';
    }
    fwrite(arr, 1, p - arr, stdout);
}
