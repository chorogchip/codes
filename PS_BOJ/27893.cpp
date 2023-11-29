#include<bits/stdc++.h>
using namespace std;

int main() {
    while(1){
    //cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string str; cin >> str;
    str += '#';
    int dot = 0;
    priority_queue<int> dot_intvs;
    int intv_sz = 0;
    int blk_cnt = 0;
    int i = 0;
    while (str[i] == '.') ++i;
    if (str[i] == 'X') ++blk_cnt;
    int asd = i;
    for (; i < n; ++i) {
        if (str[i] == '.') {
            ++dot;
            ++intv_sz;
        } else {
            if (intv_sz) {
                dot_intvs.push(-intv_sz);
                ++blk_cnt;
            }
            intv_sz = 0;
        }
    }
    intv_sz = asd;
    //cout << dot << ' ' << blk_cnt << endl;
    while(!dot_intvs.empty()) {
        int itv = -dot_intvs.top(); dot_intvs.pop();
        if (m >= itv) {
            m -= itv;
            dot -= itv;
            --blk_cnt;
        } else {
            dot -= m;
            break;
        }
    }
    //cout << dot << ' ' << blk_cnt << endl;
    cout << dot + (blk_cnt << 1) + intv_sz;
    }
}