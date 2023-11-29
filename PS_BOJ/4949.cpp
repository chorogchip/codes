#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

#include<stack>
string S;
stack<char> st;

main() {
    while (true) {
        while (st.size()) st.pop();
        getline(cin, S);
        bool toCon = false;
        if (S.length() == 1 && S[0] == '.') return 0;
        for (char c : S) {
            if (c == '(') st.push('(');
            else if (c == '[') st.push('[');
            else if (c == ')')
                if (st.size() > 0 && st.top() == '(') st.pop();
                else { toCon = true; break; }
            else if (c == ']')
                if (st.size() > 0 && st.top() == '[') st.pop();
                else { toCon = true; break; }
        }
        if (toCon || st.size()) cout << "no\n";
        else cout << "yes\n";
    }
}