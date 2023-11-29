#include<iostream>
#include<cstdlib>
#include<vector>
#define endl '\n';
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

typedef long long ll;
constexpr ll DV = 142857LL;
int C[3][37][37], F[27], MM[] = { 11, 13, 37, 27 };
int np[20], mp[20], rp[20], Nm[20], Mm[20], Rm[20], e[21];

constexpr inline int getYeokSu(ll n, ll md) {
    ll ret = 1LL;
    for (int i = md - 2; i; i >>= 1) {
        if (i & 1) ret *= n, ret %= md;
        n *= n; n %= md;
    }
    return ret;
}
inline void pre() {
    for (int mm = 0; mm != 3; ++mm) {
        int M = MM[mm];
        for (int i = 0; i != M; ++i) {
            int cc = i + 2 >> 1;
            C[mm][i][0] = 1;
            for (int j = 1; j != cc; ++j)
                C[mm][i][j] = (C[mm][i-1][j-1] + C[mm][i-1][j]) % M;
            for (int j = cc; j <= i; ++j) C[mm][i][j] = C[mm][i][i-j];
        }
    }
    F[0] = F[1] = 1;
    for (int i = 2; i != 27; ++i) F[i] = F[i-1] * i % 27;
}
inline ll getLucas(ll n, ll k, int mm, ll md) {
    ll r = 1LL;
    while (n) {
        r *= C[mm][n % md][k % md], r %= md;
        n /= md, k /= md;
    }
    return r;
}

ll mypow3(int n) {
    if (n == 1) return 3;
    ll tmp = mypow3(n>>1);
    tmp *= tmp; tmp %= 27LL;
    if (n & 1) return 3 * tmp % 27LL;
    else return tmp;
}
inline ll get3(ll n, ll k) {
    ll r = n - k;
    ll nn = n, kk = k, rr = r;
    for (int i = 0; i != 20; ++i) {
        Nm[i] = nn % 27; nn /= 3;
        Mm[i] = kk % 27; kk /= 3;
        Rm[i] = rr % 27; rr /= 3;
    }
    nn = n, kk = k, rr = r;
    for (int i = 0; i != 20; ++i) {
        np[i] = nn % 3; nn /= 3;
        mp[i] = kk % 3; kk /= 3;
        rp[i] = rr % 3; rr /= 3;
    }
    e[0] = 0;
    int ec = 0;
    for (int i = 0; i != 20; ++i) {
        e[i] += mp[i] + rp[i];
        if (e[i] >= 3) e[i] = e[i+1] = 1, ++ec;
        else e[i] = e[i+1] = 0;
    }
    ll ret = F[Nm[0]] * getYeokSu(F[Mm[0]], 27) * getYeokSu(F[Rm[0]], 27) % 27LL;
    cout << F[Nm[0]] << " " << getYeokSu(F[Mm[0]], 27) << " " << getYeokSu(F[Rm[0]], 27) << endl;
    cout << "ret : " << ret << endl;
    int ccc = 0;
    for (int i = 1; i != 20; ++i)
        ccc += Nm[i] - Mm[i] - Rm[i];
    if (ccc > 0) ret *= mypow3(ccc);
    else if (ccc < 0) ret *= getYeokSu(mypow3(-ccc), 27);
    cout << Nm[0] << " " << Mm[0] << " " << Rm[0] << " " << ccc << " " << e[0] << " " << ec <<endl;
    ret %= 27LL;
    if (e[0]) ret *= 3LL;
    if (ec & 1) ret *= -1LL;
    return ret % 27LL;
}
constexpr inline ll get1modn(ll n, ll md) {
    ll k = 1, s = n;
    while (s % md != 1) s += n, ++k;
    return k;
}
int main() { FAST
    int T; cin >> T; pre();
    while (T--) {
        ll RR[4]; int N, K; cin >> N >> K;
        for (int i = 0; i != 3; ++i)
            RR[i] = getLucas(N, K, i, MM[i]);
        RR[3] = get3(N, K);
        cout << RR[0] << " " << RR[1] << " " << RR[2] << " " << RR[3] << endl;
        for (int i = 0; i != 3; ++i)
            RR[i] *= (DV/MM[i]) * (get1modn(DV/MM[i], MM[i]));
        cout << RR[0] << " " << RR[1] << " " << RR[2] << " " << RR[3] << endl;
        cout << (RR[0] + RR[1] + RR[2] + RR[3]) % DV << endl;
    }
}
