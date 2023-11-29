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
int C[201010];
#include<queue>
queue<int> qu;
vector<int> v;

main() {
    cin >> N >> K;
    C[N] = -1;
    qu.push(N);
ST:
    S = qu.size();
    do {
        int a = qu.front(); qu.pop();
        if (a == K) {
            cout << R << endl;
            do v.push_back(K);
            while ((K = C[K] - 1) != -2);
            while (!v.empty()) cout << v.back() << ' ', v.pop_back();
            cout << endl;
            return 0;
        } else if (a < K) {
            if (!C[a<<1]) C[a<<1] = a + 1, qu.push(a<<1);
            if (!C[a +1]) C[a +1] = a + 1, qu.push(a +1);
        }
        if (a > 0 && !C[a-1]) C[a-1] = a + 1, qu.push(a-1);
    } while (--S);
    ++R;
    goto ST;
}

