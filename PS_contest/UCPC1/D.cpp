#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

typedef long long ll;
struct Tree {
    int cnt;
    bool hasdata;
    bool alread;
    ll val;
    Tree *lt, *rt;
    Tree(): cnt(0), hasdata(false), alread(false) {}
} *trees = new Tree();

void insert(Tree*& tr, ll data, ll lo, ll hi) {
    //static int i = 0;
    //if (++i < 30) cout << "insert : " << data << ' ' << lo << ' ' << hi << endl;
    ++(tr->cnt);
    ll md = lo + hi >> 1LL;
    if (!tr->hasdata && !tr->alread) {
        tr->hasdata = true;
        tr->alread = true;
        tr->val = data;
        tr->lt = new Tree();
        tr->rt = new Tree();
        return;
    }
    if (data == tr->val) return;
    tr->hasdata = false;
    if (data <= md)insert(tr->lt, data, lo, md);
    else insert(tr->rt, data, md + 1, hi);
    if (tr->val <= md)insert(tr->lt, tr->val, lo, md);
    else insert(tr->rt, tr->val, md + 1, hi);
}

bool found = false;
int asdf111(Tree*& tr, ll data, ll lo, ll hi) {
    if (tr->hasdata) {
        if (tr->val == data) {
            found = true;
            return 0;
        } else return tr->val <= data ? tr->cnt : 0;
    }
    ll md = lo + hi >> 1LL;
    if (data <= md) {
        return asdf111(tr->lt, data, lo, md);
    } else {
        return tr->lt->cnt + asdf111(tr->rt, data, md + 1, hi);
    }
}

bool isPlus = true;
bool is0 = false;
ll Q, N, A, B, C;
int main() {
    cin >> Q;
    fore (i, Q) {
        cin >> N;
        if (N == 2) {
            cin >> C;
            if (is0) {
                cout << '0' << endl;
                continue;
            }
            if (trees->cnt == 0) {
                if (isPlus) cout << '+' << endl;
                else cout << '-' << endl;
                continue;
            }
            found = false;
            int asdR = asdf111(trees, C, -(1LL<<62LL), 1LL<<62LL);
            if (found) cout << '0' << endl;
            else {
                bool bbbb = (asdR & 1) == 1;
                if (bbbb == isPlus) cout << '+' << endl;
                else cout << '-' << endl;
            }
        } else {
            cin >> A >> B;
            if (A == 0) {
                if (B < 0) isPlus = !isPlus;
                else if (B == 0) is0 = true;
                continue;
            }
            else if (B == 0) insert(trees, 0, -(1LL<<62LL), 1LL<<62LL);
            else insert(trees, ((-B + A - 1) / A), -(1LL<<62LL), 1LL<<62LL);
            
            if (A < 0) isPlus = false;
        }
    }
}
