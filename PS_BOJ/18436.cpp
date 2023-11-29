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

int N, M, C, A, B, D[101010], T1[101010], T2[101010];

void add(int i, int aa, int x) {
    if (aa&1) while (i <= N) T1[i] += x, i += i&-i;
    else while (i <= N) T2[i] += x, i += i&-i;
}
int sum(int i, int aa) {
    int s = 0;
    if (aa&1) while(i) s += T1[i], i -= i&-i;
    else while(i) s += T2[i], i -= i&-i;
    return s;
}

int main() { FAST
    cin >> N;
    for1 (i, N) cin >> D[i], add(i, D[i], 1);
    cin >> M;
    fore (i, M) {
        cin >> C >> A >> B;
        if (C == 1) {
            int d = D[A];
            D[A] = B;
            if ((d ^ B) & 1) {
                add(A, d, -1);
                add(A, B, 1);
            }
        } else if (C == 2) cout << sum(B, 0) - sum(A-1, 0) << endl;
        else cout << sum(B, 1) - sum(A-1, 1) << endl;
    }
}
