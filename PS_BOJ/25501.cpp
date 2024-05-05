#include<bits/stdc++.h>
using namespace std;

int cnt;

int recursion(const char *s, int l, int r){
    ++cnt;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        cnt = 0; cout << isPalindrome(s.c_str()) << ' ' << cnt << '\n';
    }
}