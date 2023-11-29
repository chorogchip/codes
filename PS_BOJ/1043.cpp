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

int N, M, U[52], P, PP[52], X, XX, R;

int find(int x) {
    if (U[x] == x) return x;
    return U[x] = find(U[x]);
}
void un(int a, int b) {
    a = find(a);
    b = find(b);
    U[b] = a;
}

int main() { FAST
    cin >> N >> M >> P;
    for1 (i, N) U[i] = i;
    fore (i, P) {
        cin >> X;
        un(0, X);
    }
    fore (i, M) {
        cin >> P >> XX;
        PP[i] = XX;
        for (int i = 1; i != P; ++i) {
            cin >> X;
            un(X, XX);
            XX = X;
        }
    }
    fore (i, M)
        if (find(0) != find(PP[i])) ++R;
    cout << R << endl;
}
