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

int Ts, Ps;
char T[1001010], P[1001010];
int Tl[1001010], Pl[1001010];

int main() {
    scanf("%[^\n]", T);
    getchar();
    scanf("%[^\n]", P);
    Ts = strlen(T);
    int cn = 0;
    for (int i = 0; ++i) {
        if (!P[i]) {
            Ps = i;
            break;
        }
        if (P[i] == P[cn]) {
            Pl[i] = ++cn;
            if (cn == i - st)
        } else {
            Pl[i] = 0;
            cn = 0;
        }
    }
}
