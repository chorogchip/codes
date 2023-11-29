#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int D[101];

int main() {
    vector<int>v;
    {
        int n; cin >> n;
        int st, cur;
        cin >> st; cur = st; v.push_back(st);
        for (int i = 1; i < n; ++i) {
            int x; cin >> x;
            if (cur == st) {
                cur = x;
            } else if (cur < st) {
                if (x <= cur) cur = x;
                else {
                    v.push_back(cur);
                    st = cur;
                    cur = x;
                }
            } else {
                if (x >= cur) cur = x;
                else {
                    v.push_back(cur);
                    st = cur;
                    cur = x;
                }
            }
        }
        v.push_back(cur);
    }
    int sum = 0;
    constexpr int MINF = -1000000000;
    {
        int n = v.size();
        for (int i = 0; i <= 100; ++i) D[i] = MINF;
        D[v[0]] = 0;
        for (int i = 1; i < n; ++i) {
            int m = D[v[i]];
            for (int j = 0; j <= 100; ++j) {
                int gap = j - v[i];
                m = max(m, D[j]+gap*gap);
            }
            D[v[i]] = m;
        }
    }
    int m = MINF;
    for (int i = 0; i <= 100; ++i) {
        m = max(m, D[i]);
    }
    cout << m;
}