#include <bits/stdc++.h>
using namespace std;

int b1[256], b2[256];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s1, s2; cin >> s1 >> s2;
    for (auto o : s1) ++b1[o];
    for (auto o : s2) ++b2[o];
    int wc1 = b1['@'];
    int wc2 = b2['@'];
    for (char i = 'a'; i <= 'z'; ++i) {
        int aa1 = b1[i];
        int aa2 = b2[i];
        if (i == 'a' || i == 't' || i == 'c' || i == 'o' || i == 'd' || i == 'e' || i == 'r')
        {
            if (aa1 < aa2) {
                wc1 -= aa2 - aa1;
                if (wc1 < 0) goto NO;
            } else if (aa2 < aa1) {
                wc2 -= aa1 - aa2;
                if (wc2 < 0) goto NO;
            }
        } else {
            if (aa1 != aa2) goto NO;
        }
    }

    YES: cout << "Yes"; return 0;
    NO: cout << "No"; return 0;
}