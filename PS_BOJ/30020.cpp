#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b; cin >> a >> b;
    if (a <= b) goto NO;
    {
    vector<string> ans;
    while (b + 1 < a) {
        a -= 2; b -= 1;
        ans.push_back("aba\n");
    }
    string last = "";
    if (b <= 0) goto NO;
    while(b--) last += "ab";
    last += "a\n";
    ans.push_back(last);
    cout << "YES\n" << ans.size() << '\n';
    for (auto o : ans) cout << o;
    return 0;
    }
    NO: cout << "NO";
}