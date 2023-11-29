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

#include<queue>
int N, Q, C[201010], X, Y, R[201010];
vector<int> vec[201010];

int REC(int v) {
    if (R[v] == -1) return v;
    if (R[v] > 0) return R[v];
    return R[v] = REC(C[v]);
}

MAIN { FAST
    cin >> N >> Q;
    foreach (i, N) {
        cin >> X >> Y;
        vec[X].push_back(Y);
        vec[Y].push_back(X);
    }
    X = Y = 0;
    queue<pair<int,int>> qu;
    qu.push(make_pair(1, -1));
    C[1] = -1;  // root : -1
    while (!qu.empty()) {
        auto v = qu.front(); qu.pop();
        int cc = 0;
        for (auto o : vec[v.first]) {
            if (!C[o]) {
                C[o] = v.first;
                qu.push(make_pair(o, v.first));
            } else if (v.second != o) {
                // there is loop
                X = v.first;
                Y = o;
            } else {
                cc++;
                if (cc >= 2) {
                    // there is loop
                    X = v.first;
                    Y = o;
                }
            }
        }
        vec[v.first].clear();
    }

    // loop : -1
    do R[X] = -1;
    while ((X = C[X]) != -1);
    do R[Y] = -1;
    while ((Y = C[Y]) != -1 && R[Y] != -1);
    if (Y != -1 && (Y = C[Y]) != -1) {
        do R[Y] = 0;
        while ((Y = C[Y]) != -1);
    }
    
    // else : N
    for (int i = 1; i <= N; ++i)
        if (!R[i]) REC(i);
    
    foreach (i, Q) {
        cin >> X >> Y;
        if (R[X] == -1 && R[Y] == -1) cout << 2 << endl;
        else if (R[X] == -1)
            if (R[Y] == X) cout << 1 << endl;
            else cout << 2 << endl;
        else if (R[Y] == -1)
            if (R[X] == Y) cout << 1 << endl;
            else cout << 2 << endl;
        else if (R[X] == R[Y]) cout << 1 << endl;
        else cout << 2 << endl; 
    }
}