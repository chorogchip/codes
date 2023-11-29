#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
constexpr int INF = 1000*1000*1000;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int G, P, X, S, A[101010];

int find(int x) {
    if (x == A[x]) return x;
    return A[x] = find(A[x]);
}

int main() { FAST
    cin >> G >> P;
    for1 (i, G) A[i] = i;
    fore (i, P) {
        cin >> X;
        int x = find(X);
        if (!x) goto E;
        A[x] = find(x-1);
        ++S;
    }
    E:
    cout << S;
}
