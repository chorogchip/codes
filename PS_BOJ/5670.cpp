#include<bits/stdc++.h>
using namespace std;

int res;

struct Trie {
    char c;
    Trie* next[26];

    void put(const string& s, int sz, int i) {
        
    }

} trie, pool[1010101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (!cin.eof()) {
        int n; cin >> n;
        trie = Trie{}; res = 0;
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            trie.put(s, s.size(), 0);
        }
        cout << (float)res / (float)n;
    }
}