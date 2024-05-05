#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        string s = "-";
        while(n--) {
            string s2 = s;
            for (int i = 0; i < s.size(); ++i)
                s2 += ' ';
            s2 += s;
            s = s2;
        }
        cout << s << '\n';
    }
}