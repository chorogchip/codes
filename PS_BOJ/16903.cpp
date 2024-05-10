#include<bits/stdc++.h>
using namespace std;

struct {
private:
    struct Node { int l,r,cnt,ter; Node():l(-1),r(-1),cnt(0),ter(-1){} };
    Node node[6060606]; vector<int> qu;
    int alloc_node() { int ret = qu.back(); qu.pop_back(); return ret; }
    void free_node(int id) { qu.push_back(id); }
    int root;
public:
    void init() {
        qu.reserve(6060606);
        for (int i = 6060605; i > 0; --i) qu.push_back(i);
        root = alloc_node();
    }
    void insert(int x) {
        int now = root;
        for (int i = 29; i >= 0; --i) {
            if (x & 1<<i) {
                if (node[now].r == -1) node[now].r = alloc_node();
                now = node[now].r;
                node[now].cnt++;
                if (i == 0) node[now].ter = x;
            } else {
                if (node[now].l == -1) node[now].l = alloc_node();
                now = node[now].l;
                node[now].cnt++;
                if (i == 0) node[now].ter = x;
            }
        }
    }
    void erase(int x) {
        int now = root;
        for (int i = 29; i >= 0; --i) {
            if (x & 1<<i) {
                int nxt = node[now].r;
                if (--node[nxt].cnt == 0) {
                    node[now].r = -1; node[nxt].ter = -1; free_node(nxt);
                }
                now = nxt;
            } else {
                int nxt = node[now].l;
                if (--node[nxt].cnt == 0) {
                    node[now].l = -1; node[nxt].ter = -1; free_node(nxt);
                }
                now = nxt;
            }
        }
    }
    int query(int x) {
        int now = root;
        for (int i = 29; i >= -1; --i) {
            if (node[now].ter != -1) return x ^ node[now].ter;
            if (x & 1<<i) {
                if (node[now].l != -1) now = node[now].l;
                else now = node[now].r;
            } else {
                if (node[now].r != -1) now = node[now].r;
                else now = node[now].l;
            }
            if (node[now].ter != -1) return x ^ node[now].ter;
        }
        return x;
    }
} trie;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    trie.init();
    int q; cin >> q;
    while(q--) {
        int a, x; cin >> a >> x;
        if (a == 1) trie.insert(x);
        else if (a == 2) trie.erase(x);
        else cout << trie.query(x) << '\n';
    }
}