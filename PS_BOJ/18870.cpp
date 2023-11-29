#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, R[1010101];
pair<int,int> D[1010101];

main() { FAST

    cin >> N;
    fore(i, N) cin >> D[i].first, D[i].second = i;
    sort(D, D + N, [](pair<int,int>a,pair<int,int>b)->bool{
        return a.first < b.first;
    });
    int count = 0;
    R[D[0].second] = 0;
    for (int i = 1; i != N; ++i) {
        if (D[i].first != D[i-1].first) R[D[i].second] = ++count;
        else R[D[i].second] = count;
    }
    fore (i, N) cout << R[i] << " ";
}