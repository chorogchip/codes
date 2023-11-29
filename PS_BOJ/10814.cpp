#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N;
pair<int, string> V[101010];

main() { FAST

    cin >> N;
    fore(i, N) cin >> V[i].first >> V[i].second;
    stable_sort(V, V + N, [](pair<int,string>a, pair<int,string>b)->bool{
        return a.first < b.first;
    });
    fore(i, N) cout << V[i].first << " " << V[i].second << endl;

}