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

pair<char,pair<int,int>> trees[30];
int N;
char A, B, C;
void asdf1(int i) {
    cout << trees[i].first;
    if (trees[i].second.first) asdf1(trees[i].second.first);
    if (trees[i].second.second) asdf1(trees[i].second.second);
}
void asdf2(int i) {
    if (trees[i].second.first) asdf2(trees[i].second.first);
    cout << trees[i].first;
    if (trees[i].second.second) asdf2(trees[i].second.second);
}
void asdf3(int i) {
    if (trees[i].second.first) asdf3(trees[i].second.first);
    if (trees[i].second.second) asdf3(trees[i].second.second);
    cout << trees[i].first;
}
int main() { FAST
    cin >> N;
    fore (i, N) {
        cin >> A >> B >> C;
        auto& t = trees[A-'@'];
        t.first = A;
        if (B != '.') t.second.first = B-'@';
        if (C != '.') t.second.second = C-'@';
    }
    asdf1(1); cout << endl;
    asdf2(1); cout << endl;
    asdf3(1); cout << endl;
}
