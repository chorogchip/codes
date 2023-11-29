#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

char A[1010101], B[1010101], C[40], D[1010101];

int main() {
    fgets(A, 1010101, stdin);
    fgets(C, 40, stdin);
    char c;
    int k = 0, j = 0, l = strlen(C) - 1;
    for (int i = 0; (c = A[i]) != '\n'; ++i) {
        if (c != C[k]) {
            if (c == C[0]) {
                D[j] = A[i];
                B[j++] = k = 1;
            } else {
                D[j] = A[i];
                B[j++] = k = 0;
            }
        } else if (++k == l) {
            j -= l - 1;
            k = j ? B[j-1] : 0;
        } else {
            D[j] = A[i];
            B[j++] = k;
        }
    }
    if (j) fwrite(D, 1, j, stdout);
    else puts("FRULA");
}
