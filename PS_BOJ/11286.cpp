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

int N, X;
#include<queue>
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> hsh;

int main() { FAST
    cin >> N;
    fore (i, N) {
        cin >> X;
        if (X) hsh.push(make_pair(abs(X), X));
        else if (hsh.empty()) cout << 0 << endl;
        else cout << hsh.top().second << endl, hsh.pop();
    }
}
