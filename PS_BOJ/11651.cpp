#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

pair<int,int> V[101010];
int N, X, Y;

main() { FAST

    cin >> N;
    fore(i, N) {
        cin >> X >> Y;
        V[i] = make_pair(Y, X);
    }
    sort(V, V + N);
    for (int i = 0; i != N; ++i) {
        cout << V[i].second << " " << V[i].first << endl;
    }


}