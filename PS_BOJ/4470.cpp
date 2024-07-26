#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    char buf[128]; cin.getline(buf, sizeof(buf));
    for (int i = 1; i <= n; ++i) {
        cin.getline(buf, sizeof(buf));
        cout << i << ". " << buf << '\n';
    }
}