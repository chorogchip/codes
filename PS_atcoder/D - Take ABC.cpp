#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s1, s2; cin >> s1;
    for (int i = 0; i < s1.size(); ++i) {
        s2 += s1[i];
        int s = s2.size();
        if (s >= 3 && s2[s-1] == 'C' && s2[s-2] == 'B' && s2[s-3] == 'A')
            s2.pop_back(), s2.pop_back(), s2.pop_back();
    }
    cout << s2;
}