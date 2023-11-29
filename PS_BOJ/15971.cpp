#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

struct Line{int to,len;Line(int a,int b):to(a),len(b){}};
int N, A, B, X, Y, Z;
bool C[101010];
vector<Line> G[101010];
int S, M;

bool DFS(int v) {
    if (v == B) return true;
    bool isT = false;
    for (auto o : G[v])
        if (!C[o.to]) {
            C[o.to] = true;
            if (DFS(o.to)) {
                S += o.len;
                M = max(M, o.len);
                isT = true;
                break;
            }
        }
    return isT;
}

MAIN { FAST
    cin >> N >> A >> B;
    for (int i = 1; i != N; ++i) {
        cin >> X >> Y >> Z;
        G[X].push_back(Line(Y, Z));
        G[Y].push_back(Line(X, Z));
    }
    C[A] = true;
    DFS(A);
    cout << S - M;
}