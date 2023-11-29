#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

#include<queue>
int N, K, i;
queue<int> qu;

main() { FAST
    cin >> N >> K;
    while (i++ != N) qu.push(i);
    for (int k = 1; k != K; ++k) qu.push(qu.front()), qu.pop();
    cout << "<" << qu.front(), qu.pop();
    for (i = 1; i != N; ++i) {
        for (int k = 1; k != K; ++k) qu.push(qu.front()), qu.pop();
        cout << ", " << qu.front(), qu.pop();
    }
    cout << ">";
}