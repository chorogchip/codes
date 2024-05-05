#include<bits/stdc++.h>
using namespace std;

struct Trie {
    map<string, Trie*> t;
    Trie* operator+(const string& s) {
        if (!t.contains(s)) t.insert({s, new Trie{}});
        return t[s];
    }
    void print(int ind) {
        for (auto o : t) {
            for (int i = 0; i < ind; ++i) cout << "--";
            cout << o.first << '\n';
            o.second->print(ind + 1);
        }
    }
} trie;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while(n--) {
        int k; cin >> k;
        Trie* t = &trie;
        while(k--) {
            string s; cin >> s;
            t = *t + s;
        }
    }
    trie.print(0);
}