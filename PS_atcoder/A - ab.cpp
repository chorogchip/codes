#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    string str; cin >> str;
    for (int i = 1; i < n; ++i) {
        if (str[i] == 'a' && str[i-1] == 'b' || str[i] == 'b' && str[i-1] == 'a')
        goto YES;
    }
    cout << "No"; exit(0);
    YES: cout << "Yes"; exit(0);
}