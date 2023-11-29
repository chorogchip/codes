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

#include<queue>
queue<int> qu;
int N, K;

int main() { FAST
    cin >> N >> K;
    --K;
    cout << "<";
    for (int i = 1; i <= N; ++i) qu.push(i);
    fore (a, N) {
        fore (b, K) qu.push(qu.front()), qu.pop();
        cout << qu.front(); qu.pop();
        if (!qu.empty()) cout << ", ";
    }
    cout << ">\n";
}
