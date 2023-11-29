#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define LL long long
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int n, k, coins[101];
int use[2][10001];

MAIN { FAST
    cin >> n >> k;
    use[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> coins[i];
        for (int j = 0; j <= k; ++j) use[i & 1][j] = 0;
        for (int j = 0; j <= k; ++j)
            for (int count = 0; j - count * coins[i] >= 0; ++count)
                use[i & 1][j] += use[(i - 1) & 1][j - count * coins[i]];
    }
    cout << use[n & 1][k];
}