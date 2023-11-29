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

vector<pair<int,pair<int,int>>> trees;
int N;
void insert(int v, int d) {
    if (d < trees[v].first)
        if (trees[v].second.first) insert(trees[v].second.first, d);
        else trees[v].second.first = trees.size(),
             trees.push_back(make_pair(d, make_pair(0, 0)));
    else
        if (trees[v].second.second) insert(trees[v].second.second, d);
        else trees[v].second.second = trees.size(),
             trees.push_back(make_pair(d, make_pair(0, 0)));
}
void search(int v) {
    if (trees[v].second.first) search(trees[v].second.first);
    if (trees[v].second.second) search(trees[v].second.second);
    cout << trees[v].first << endl;
}
int main() { FAST
    cin >> N;
    trees.push_back(make_pair(N, make_pair(0, 0)));
    while (cin >> N) insert(0, N);
    search(0);
}
