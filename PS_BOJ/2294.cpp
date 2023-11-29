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
unsigned int use[2][10001];

MAIN { FAST
    cin >> n >> k;
    for (int j = 1; j <= k; ++j) use[0][j] = -1U;
    use[0][0] = 0U;
    for (int i = 1; i <= n; ++i) {
        cin >> coins[i];
        for (int j = 0; j <= k; ++j) {
            use[i & 1][j] = use[i - 1 & 1][j];
            if (j - coins[i] >= 0 && use[i & 1][j - coins[i]] != -1)
                use[i & 1][j] = std::min(use[i & 1][j], use[i & 1][j - coins[i]] + 1);
        }
    }
    cout << (int)use[n & 1][k];
}