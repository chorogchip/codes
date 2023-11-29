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

int N, K, R, S;
pair<int,int> C[201010];
#include<queue>
queue<int> qu;

main() { FAST
    cin >> N >> K;
    C[N].first = 1, C[N].second = -1;
    qu.push(N);
ST:
    S = qu.size();
    do {
        int a = qu.front(); qu.pop();
        if (a == K) {
            cout << R << endl << C[K].first << endl;
            return 0;
        } else if (a < K) {
            if (C[a<<1].second == 0) C[a<<1].first += C[a].first, C[a<<1].second = R, qu.push(a<<1);
            else if (C[a<<1].second == R) C[a<<1].first += C[a].first;
            if (C[a +1].second == 0) C[a +1].first += C[a].first, C[a +1].second = R, qu.push(a +1);
            else if (C[a +1].second == R) C[a +1].first += C[a].first;
        }
        if (a > 0) {
            if (C[a-1].second == 0)
                C[a-1].first += C[a].first, C[a-1].second = R, qu.push(a-1);
            else if (C[a-1].second == R)
                C[a-1].first += C[a].first;
        }
    } while (--S);
    ++R;
    goto ST;
}

