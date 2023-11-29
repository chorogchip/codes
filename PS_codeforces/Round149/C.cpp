#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        string str; cin >> str;
        str = "0" + str + "1";
        for (int i = 1; i < str.size() - 1; ++i) {
            if (str[i] == '0') cout << '0';
            else if (str[i] == '1') cout << '1';
            else {
                cout << str[i-1];
                str[i] = str[i-1];
            }
        }
        cout << '\n';
    }
}
