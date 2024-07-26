#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[2][4096*4][32];

int main() {
    int n; scanf("%d", &n);
    
    deque<pair<pair<int,int>,pair<int,int>>> v;
    for (int i = 1; i <= n; ++i) {
        int a; scanf("%d", &a);
        for (int aa = 1; aa <= a; ++aa) {
            int sc, b, c, d, e, f;
            scanf("%d %d %d:%d %d:%d", &sc, &b, &c, &d, &e, &f);
            b--;
            int st = b*24*60 + c*60 + d;
            int fn = b*24*60 + e*60 + f;
            v.push_back({{fn, st},{sc, aa}});
        }
        sort(v.begin(), v.end());
    }


    for (int time = 0; time <= 7*24*60; ++time)
        dp[0][time][0] = 1;


    for (int i = 1; i <= n; ++i) {
        auto& src = dp[i+1&1];
        auto& dst = dp[i&1];


        memset(dst, 0, sizeof(dst));
        int asum[23]; memset(asum, 0, sizeof(asum));

        for (int time = 0; time <= 7*24*60; ++time) {
            while (!v.empty() && v.front().first.first == time) {
                auto [tm, gr] = v.front(); v.pop_front();
                auto [fn, st] = tm;
                for (int sc = 0; sc <= 22; ++sc)
                    if (sc + gr <= 22)
                        asum[sc+gr] += src[st][sc];
            }
            for (int sc = 0; sc <= 22; ++sc)
                dst[time][sc] = asum[sc];
        }
        cout << "try " << i << ": \n";
        for (int sc = 0; sc <= 22; ++sc) cout << asum[sc] << ' '; cout << '\n';

        
        for (int time = 0; time <= 7*24*60; ++time)
            for (int sc = 0; sc <= 22; ++sc)
                dst[time][sc] += src[time][sc];
    }
    printf("%lld", dp[n&1][7*24*60][22]);
}