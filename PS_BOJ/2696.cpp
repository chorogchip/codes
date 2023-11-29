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

priority_queue<int> lh;
priority_queue<int,vector<int>,greater<int>> rh;
int T, N, A, B, M;

int main() { FAST
    cin >> T;
    do {
        while (!lh.empty()) lh.pop();
        while (!rh.empty()) rh.pop();
        cin >> N;
        cout << (1 + (N >> 1)) << endl;
        cin >> M;
        cout << M;
        ++N;
        int k = 1;
        while (N -= 2) {
            cin >> A >> B;
            if (A > B) swap(A, B);
            if (A <= M && M <= B) lh.push(A), rh.push(B);
            else if (B < M) lh.push(A), lh.push(B), rh.push(M), M = lh.top(), lh.pop();
            else rh.push(A), rh.push(B), lh.push(M), M = rh.top(), rh.pop();
            if (k == 10) cout << endl, k = 1;
            else cout << ' ';
            cout << M;
            ++k;
        };
        cout << endl;
    } while (--T);
}
