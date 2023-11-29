#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

pair<int,int> D[101010];
pair<int,vector<int>> T[101010];
int N, tmp;
void insert(int target, int data) {
    bool isS = false;
    for (auto o : T[target].second) if (D[o].first <= D[data].first && D[data].second <= D[o].second)
        insert(o, data), isS = true;
    if(!isS) T[target].second.push_back(data);
}
int search(int target) {
    int max = 0, s = T[target].second.size();
    for (int i = 0; i != s; ++i) {
        if ((tmp = search(T[target].second[i])) > max) {
            max = tmp;
            T[target].first = i;
        }
    }
    return max + 1;
}
void prtsearch(int target) {
    if ((tmp = T[target].first) != -1) {
        cout << D[T[target].second[tmp]].first << " " << D[T[target].second[tmp]].second << endl;
        prtsearch(T[target].second[tmp]);
    }
}
int main() { FAST
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> D[i].first >> D[i].second, T[i].first = -1;
    sort(D + 1, D + N + 1, [](pair<int,int>a,pair<int,int>b)->bool{
        return abs(a.first - a.second) > abs(b.first - b.second);
    });
    for (int i = 1; i <= N; ++i) insert(0, i);
    cout << search(0) - 1 << endl;
    prtsearch(0);
    /*
    cout << endl << endl;
    for (int i = 0; i <= N; ++i) cout << D[i].first << " " << D[i].second << endl;
    for (int i = 0; i <= N; ++i) { cout << T[i].first << "   ";
        for (auto o : T[i].second) cout << o << " "; cout << endl; }*/
}