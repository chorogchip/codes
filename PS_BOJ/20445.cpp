#include <bits/stdc++.h>
using namespace std;

int start_table[101], end_table[101];
unsigned int dist[128][128];
pair<int,int> intvs[101];

int srt_table(int* table, int n) {
    int sz = 1;
    sort(table, table + n);
    for (int i = 1; i < n; ++i)
        if (table[i - 1] != table[i])
            table[sz++] = table[i];
    return sz;
}

unsigned int &get_dist(pair<int,int> intv, int ssize, int esize) {
    return dist
        [lower_bound(start_table, start_table + ssize, intv.first) - start_table]
        [lower_bound(end_table, end_table + esize, intv.second) - end_table];
}

int main() {
    int n, q; cin >> n >>  q;
    for (int i = 0; i < n; ++i) {
        cin >> intvs[i].first >> intvs[i].second;
        start_table[i] = intvs[i].first;
        end_table[i] = intvs[i].second;
    }
    memset(dist, -1, sizeof(dist));
    const int s_size = srt_table(start_table, n);
    const int e_size = srt_table(end_table, n);
    for (int i = 0; i < n; ++i) {
        auto& dst = get_dist(intvs[i], s_size, e_size);
        dst = min(dst, intvs[i].second - intvs[i].first + 1U);
    }
    for (int i = 0; i < s_size; ++i) {
        for (int j = i; j < s_size; ++j) {
            // O(nlogn) needed
            
        }
    }
}