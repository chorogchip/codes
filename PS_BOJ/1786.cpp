#include<bits/stdc++.h>
using namespace std;

vector<int> gen_pi(const char* p, int n) {
    vector<int> pi(n);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && p[i] != p[j]) j = pi[j-1];
        if (p[i] == p[j]) pi[i] = j++ + 1;
    }
    return pi;
}

char buf1[100'0001], buf2[100'0001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin.getline(buf1, sizeof(buf1));
    cin.getline(buf2, sizeof(buf2));
    const char *p1 = buf1, *p2 = buf2;
    while (*p1) ++p1; while (*p2) ++p2;
    int sz1 = p1 - buf1, sz2 = p2 - buf2;
    const vector<int> pi = gen_pi(buf2, sz2);
    vector<int> res;
    for (int i = 0, j = 0; i < sz1; ++i) {
        while (j > 0 && buf1[i] != buf2[j]) j = pi[j-1];
        if (buf1[i] == buf2[j]) {
            if (j == sz2-1) res.push_back(i - sz2 + 2), j = pi[j];
            else ++j;
        }
    }
    cout << res.size() << '\n';
    for (auto o : res) cout << o << ' ';
}