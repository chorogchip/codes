#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

enum class typ {ST, EN};
int N, K, X1, X2, Y1, Y2, prvX;
struct P {
    typ type;
    int xp, yb, ye;
} Ps[401010];
ll S;

int main() { FAST
    cin >> N;
    do {
        cin >> X1 >> X2 >> Y1 >> Y2;
        Ps[K++] = {typ::ST, X1, Y1, Y2};
        Ps[K++] = {typ::EN, X2, Y1, Y2};
    } while (--N);
    sort(Ps, Ps + (N << 1), [](const P& a, const P& b)->bool{
        return a.xp < b.xp;
    });
    fore (i, N << 1) {
        //lazy
        S += (Ps[i].xp - prvX) * (1);
        prvX = Ps[i].xp;
    }
}
