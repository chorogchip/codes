#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int arr[21], tmp[21];
    for (int i = 1; i <= 20; ++i) arr[i] = i;
    for (int i =0; i < 10; ++i) {
        int a, b; cin >> a >> b;
        for (int i = a; i <= b; ++i) tmp[i] = arr[i];
        for (int i = 0; i <= b-a; ++i) arr[i+a] = tmp[b-i];
    }
    for (int i = 1; i <= 20; ++i) cout << arr[i] << ' ';
}