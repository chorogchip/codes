#include<bits/stdc++.h>
using namespace std;

int a[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, p; cin >> n >> p;
    int x = n;
    int t = 1;
    while (true) {
        x = x * n % p;
        if (!a[x]) a[x] = t++;
        else {
            cout << t - a[x];
            exit(0);
        }
    }
}