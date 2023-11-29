#include<bits/stdc++.h>
using namespace std;

int n, par, del, t[64];
vector<int> child[64];

int find(int p) {
    if (p == del) return 0;
    if (child[p].size() == 0) return 1;
    int res = 0;
    for (auto o : child[p]) res += find(o);
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        if (t[i] == -1) par = i;
        else child[t[i]].push_back(i);
    }
    cin >> del;
    auto& vec = child[t[del]];
    for (auto it = vec.begin(); it != vec.end(); ++it)
        if (*it == del) {
            vec.erase(it);
            break;
        }
    cout << find(par);
}