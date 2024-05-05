#include<bits/stdc++.h>
using namespace std;

struct TR {
    int arr[26];
} tr[8010 * 2010];
int cnt = 1;

void insert(int i, int index, const string& s) {
    char c = s[index];
    if (tr[i].arr[c-'a'] == 0) tr[i].arr[c-'a'] = cnt++;
    insert(tr[i].arr[c-'a'], index+1, s);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    while(n--) {
        string s; cin >> s;
        insert(0, 0, s);
    }
}