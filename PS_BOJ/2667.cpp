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

int N, D[30][30], R;
vector<int> v;
#include<queue>
queue<pair<int,int>> qu;

int main() {
    scanf("%d", &N); getchar();
    fore (i, N) { fore (j, N) D[i][j] = getchar() - '0'; getchar(); }
    fore (i, N) fore (j, N) if (D[i][j]) {
        D[i][j] = 0;
        R = 1;
        qu.push(make_pair(i, j));
        while (!qu.empty()) {
            auto o = qu.front(); qu.pop();
            int i = o.first, j = o.second;
            if (i-1>=0 && D[i-1][j]) { D[i-1][j] = 0; ++R; qu.push(make_pair(i-1, j)); }
            if (i+1< N && D[i+1][j]) { D[i+1][j] = 0; ++R; qu.push(make_pair(i+1, j)); }
            if (j-1>=0 && D[i][j-1]) { D[i][j-1] = 0; ++R; qu.push(make_pair(i, j-1)); }
            if (j+1< N && D[i][j+1]) { D[i][j+1] = 0; ++R; qu.push(make_pair(i, j+1)); }
        }
        v.push_back(R);
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (auto o : v) cout << o << endl;
}
