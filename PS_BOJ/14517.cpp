#include<bits/stdc++.h>
using namespace std;

const int M = 10'007;
int cnt_from[1024];
int acc_from[1024];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str; cin >> str;
    int sz = str.size();
    for (int i = 0; i < sz; ++i) {
        int acc = 1;
        acc_from[i] = 1;
        for (int j = i-1; j >= 0; --j) {
            if (str[j] == str[i]) acc += 1 + cnt_from[j+1], acc %= M;
            acc_from[j] = acc;
        }

        for (int j = 0; j <= i; ++j) {
            cnt_from[j] += acc_from[j];
            cnt_from[j] %= M;
            acc_from[j] = 0;
        }
    }
    cout << cnt_from[0];
}