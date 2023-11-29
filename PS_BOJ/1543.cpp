#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == b[0]) {
            for (int j = 0; j < b.size(); ++j) {
                if (i + j >= a.size()) goto NO;
                if (a[i + j] != b[j]) goto NO;            
            }
            ++cnt; i += b.size() - 1;
            NO:;
        }
    }
    cout << cnt;
}