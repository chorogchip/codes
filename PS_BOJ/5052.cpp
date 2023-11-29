#include<bits/stdc++.h>
using namespace std;

string arr[10101];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) cin >> arr[i];
        sort(arr, arr + n, [](const string& a, const string& b) -> bool {
            int minlen = min(a.size(), b.size());
            for (int i = 0; i < minlen; ++i)
                if (a[i] != b[i]) return a[i] < b[i];
            return a.size() < b.size();
        });
        for (int i = 0; i < n - 1; ++i) {
            const string& a = arr[i];
            const string& b = arr[i + 1];
            int minlen = min(a.size(), b.size());
            for (int j = 0; j < minlen; ++j)
                if (a[j] != b[j]) goto CON;
            goto NO;
            CON:;
        }
        YES: cout << "YES\n"; continue;
        NO: cout << "NO\n"; continue;
    }
}