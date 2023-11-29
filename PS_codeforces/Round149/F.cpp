#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

pii arr[301010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i].x;
            arr[i].y = i;
        }
        sort(arr, arr + n);
        for (int i = 0; i < n; ++i) {
            swap(arr[i].x, arr[i].y);
        }
        sort(arr, arr + k);
        sort(arr + k, arr + n);
        ll ls = 0, rs = 0;
        int lll = 0, rr = k - 1;
        while (lll <= rr) {
            if (ls < rs) ls += arr[lll++].y;
            else rs += arr[rr--].y;
        }
        ll res = max(ls, rs);
        if (ls < rs)
        {
            int smll = k;
            for (int i = k + 1; i < arr[rr+1].x; ++i)
                if (arr[smll].y > arr[i].y) smll = i;
            int bigg = k - 1;
            for (int i = k - 2; i > rr; --i)
                if (arr[bigg].y < arr[i].y) bigg = i;
            ls += arr[smll].y;
            rs -= arr[bigg].y;
            ls -= arr[lll-1].y;
            rs += arr[lll-1].y;
            res = min(res, max(ls, rs));
        } else {
            int smll = n - 1;
            for (int i = n - 2; i > arr[lll-1].x; --i)
                if (arr[smll].y > arr[i].y) smll = i;
            int bigg = 0;
            for (int i = 0; i < lll; ++i)
                if (arr[bigg].y < arr[i].y) bigg = i;
            ls -= arr[bigg].y;
            rs += arr[smll].y;
            rs -= arr[rr+1].y;
            ls += arr[rr+1].y;
            res = min(res, max(ls, rs));
        }
        cout << res << '\n';
    }
}
