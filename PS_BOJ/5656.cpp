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

string S;
int A, B, C, I;


void a(int a) {
    if (a) cout << "true\n";
    else cout << "false\n";
}
int main() { FAST
    while (true) {
        ++I;
        cin >> A >> S >> B;
        if (S[0] == 'E') return 0;
        cout << "Case " << I << ": ";
        if (S[0] == '!') a(A != B);
        else if (S[0] == '=') a(A == B);
        else if (S[0] == '<')
            if (S[1] == '=') a(A <= B);
            else a(A < B);
        else if (S[0] == '>')
            if (S[1] == '=') a(A >= B);
            else a(A > B);
    }
}
