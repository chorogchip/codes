#include<bits/stdc++.h>
using namespace std;

int arr[201010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int i = 0, s = 0, mx = 0;
    for (; i < k; ++i) { cin >> arr[i]; s += arr[i];}
    mx = s;
    for (; i < n; ++i) {
        cin >> arr[i];
        s += arr[i];
        s -= arr[i-k];
        mx = max(mx, s);
    }
    cout << mx;
}