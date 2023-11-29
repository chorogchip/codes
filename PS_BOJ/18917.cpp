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

ll M, A, S, X;

int main() { FAST
    cin >> M;
    fore (i, M) {
        cin >> A;
        if (A == 3) cout << S << endl;
        else if (A == 4) cout << X << endl;
        else if (A == 1) cin >> A, S += A, X ^= A;
        else if (A == 2) cin >> A, S -= A, X ^= A;
    }
}
