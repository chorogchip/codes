#define TEMM
#ifdef TEMM
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
struct Pos {int x,y;};
typedef long long ll;
typedef vector<int> vi;
typedef vector<Pos> vp;
constexpr int INF = 1000*1000*1000;
using namespace std;
#endif

int N, D[501010], M, X;

int main() { FAST
    cin >> N;
    fore (i, N) cin >> D[i];
    sort(D, D + N);
    cin >> M;
    fore (i, M) {
        cin >> X;
        int* x = lower_bound(D, D + N, X);
        cout << (int)(x != D + N && *x == X) << ' ';
    }
    

}
