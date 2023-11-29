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

char C[202];

char gc() {
    static int i = 0;
    return C[i++];
}

inline int getOpPriority(char c) {
    switch(c) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
    }
    return 0;
}
inline int opCmp(char a, char b) {
    return getOpPriority(a) - getOpPriority(b);
}

struct Tree {
    Tree(char cc):c(cc),l(nullptr),r(nullptr),asd(false){}
    char c;
    bool asd;
    Tree *l, *r;
};

void putD(Tree*& t, Tree* data) {
    if (t == nullptr) {
        t = data;
        return;
    }
    if (t->r == nullptr) {
        t->r = data;
        return;
    }
    putD(t->r, data);
}

void putOp(Tree*& t, char op) {
    if (t->l == nullptr) {
        t->l = new Tree(t->c);
        t->c = op;
        return;
    }
    if (!t->asd && opCmp(t->c, op) < 0) {
        putOp(t->r, op);
        return;
    }
    Tree* tmp = t;
    t = new Tree(op);
    t->l = tmp;
}

void getT(Tree *&t) {
    while (true) {
        char c = gc();
        if (c == '\n' || c == ')' || c == '\0') return;
        Tree* tt = nullptr;
        if (c == '(') {
            getT(tt);
            tt->asd = true;
        } else tt = new Tree(c);
        putD(t, tt);
        c = gc();
        if (c == '\n' || c == ')' || c == '\0') return;
        putOp(t, c);
    }
}

void DFS(Tree* t) {
    if (t != nullptr) {
        DFS(t->l);
        DFS(t->r);
        cout << t->c;
    }
}

int main() {
    cin >> C;
    struct Tree *tree = nullptr;
    getT(tree);
    DFS(tree);
    cout << endl;
}
