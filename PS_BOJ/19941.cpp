#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    string str; cin >> str;
    int sz = str.size();
    int ham = 0;
    int res = 0;
    while (ham < sz && str[ham] != 'H') ++ham;
    for (int i = 0; i < sz; ++i) if (str[i] == 'P') {
        while(true) {
            if (ham == sz) goto R;
            int gap = ham - i;
            if (gap > k) break;
            else if (gap >= -k) {
                ++res; ++ham;
                while (ham < sz && str[ham] != 'H') ++ham;
                break;
            } else {
                ++ham;
                while (ham < sz && str[ham] != 'H') ++ham;
            }
        }
    }
    R:
    cout << res;
}