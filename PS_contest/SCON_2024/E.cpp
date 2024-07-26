#include<bits/stdc++.h>
using namespace std;

struct A {
    bool val;
    bool op_and;
};

bool start;
vector<A> v;

int calc_true(int i) {
    if (i == -1) {
        if (start) return 0;
        else return 1;
    }
    if (v[i].op_and && v[i].val) { // &T
        return min(1, calc_true(i-1));
    } else if (v[i].op_and && !v[i].val) { // &F
        return min(2, calc_true(i-1)+1);
    } else if (!v[i].op_and && v[i].val) { // |T
        return 0;
    } else { // |F
        return min(1, calc_true(i-1));
    }
}

int calc_false(int i) {
    if (i == -1) {
        if (start) return 1;
        else return 0;
    }
    if (v[i].op_and && v[i].val) { // &T
        return min(1, calc_false(i-1));
    } else if (v[i].op_and && !v[i].val) { // &F
        return 0;
    } else if (!v[i].op_and && v[i].val) { // |T
        return min(2, calc_false(i-1)+1);
    } else { // |F
        return min(1, calc_false(i-1));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    char c; cin >> c;
    start = c=='T';
    for (int i = 2; i <= n; i += 2) {
        A a;
        cin >> c; a.op_and = c=='&';
        cin >> c; a.val = c=='T';
        v.push_back(a);
    }
    cin >> c;
    if (c == 'T') cout << calc_true(n/2-1);
    else cout << calc_false(n/2-1);
}