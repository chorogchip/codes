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

int N, S, X, Y;
pair<int,int> D[101010];

MAIN { FAST
    cin >> N;
    foreach (i, N)  {
        cin >> X >> Y;
        D[i] = make_pair(X, Y);
    }
    sort(D, D + N, [](pair<int,int>p1,pair<int,int>p2)->bool{
        if (p1.second != p2.second) return p1.second < p2.second;
        return p1.first < p2.first;
    });
    int hi = 0;
    foreach (i, N)
        if (D[i].first >= hi) hi = D[i].second, S++;
    cout << S;
}