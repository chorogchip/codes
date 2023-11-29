#include<bits/stdc++.h>
using namespace std;

short arr[2][1024];
const short INF = 3'0000;
char buf[2048];

int main() {
    fread(buf, 1, 2048, stdin);
    int ii = 0; while(buf[ii] != '\n') ++ii;
    int jj = 1; while(buf[ii + jj] != '\n') ++jj;
    const char* as = buf - 1;
    const char* bs = buf + ii;
    ++ii;
    if (ii > jj) swap(ii, jj), swap(as, bs);

    for (int j = 1; j < jj; ++j) arr[0][j] = j;

    for (int i = 1; i < ii; ++i) {
        short prev = arr[1][0] = i;
        for (int j = 1; j < jj; ++j) {
            prev = arr[1][j] = 1 + min((short)(arr[0][j-1] - (as[i] == bs[j])), min(arr[0][j], prev));
        }
        if (++i >= ii) break;
        prev = arr[0][0] = i;
        for (int j = 1; j < jj; ++j)
            prev = arr[0][j] = 1 + min((short)(arr[1][j-1] - (as[i] == bs[j])), min(arr[1][j], prev));
    }
    printf("%d", arr[(ii-1) & 1][jj-1]);
}