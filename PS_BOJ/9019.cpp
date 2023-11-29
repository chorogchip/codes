#include<iostream>
#include<cstdlib>
#include<cstring>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

pair<short,char> D[10001];
int T, A, B;
constexpr int M = 10000;

int main() { FAST
    cin >> T;
    while (T--) {
        short qu[10101];
        int fr = 0, bk = 0;
        char v[20101];
        int vs = 0;
        memset(D, 0, sizeof(D));
        cin >> A >> B;
        qu[fr++] = A; fr %= M+2; D[A].first = -1;
        while (true) {
            auto o = qu[bk++]; bk %= M+2;
            int oo, ooo;
            if (o == B) {
                do v[vs++] = D[o].second; while (D[o = D[o].first-1].first != -1);
                break;
            }
            oo = (o << 1) % M;
            if (!D[oo].first) D[oo].first = o+1, D[oo].second = 'D', qu[fr++] = oo, fr %= M+2;
            oo = (o - 1 + M) % M;
            if (!D[oo].first) D[oo].first = o+1, D[oo].second = 'S', qu[fr++] = oo, fr %= M+2;
            ooo = o / 1000;
            oo = (o * 10) % M + ooo;
            if (!D[oo].first) D[oo].first = o+1, D[oo].second = 'L', qu[fr++] = oo, fr %= M+2;
            ooo = o % 10;
            oo = (o / 10) + ooo * 1000;
            if (!D[oo].first) D[oo].first = o+1, D[oo].second = 'R', qu[fr++] = oo, fr %= M+2;
        }
        for (int i = vs - 1; i >= 0; --i) cout << v[i];
        cout << endl;
    }
}
