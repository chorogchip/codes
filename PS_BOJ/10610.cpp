#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str; cin >> str;
    sort(str.begin(), str.end());
    reverse(str.begin(), str.end());
    int sum = 0; for (auto o : str) sum += o - '0'; sum %= 3;
    if (sum != 0 || str.back() != '0') str = "-1";
    cout << str;
}