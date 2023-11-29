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

bool isM(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() { FAST
    while (true) {
        cin >> S;
        if (S == "end") return 0;
        int s = S.size();
        for (int i = 0; i != s; ++i) if (isM(S[i])) goto SEC;
        goto FAIL;
        SEC:
        for (int i = 2; i < s; ++i) if (isM(S[i]) == isM(S[i-1]) && isM(S[i-1]) == isM(S[i-2])) goto FAIL;
        for (int i = 1; i < s; ++i) if (S[i] == S[i-1] && S[i] != 'o' && S[i] != 'e') goto FAIL;
        SUCCEED: cout << "<" << S << "> is acceptable.\n"; continue;
        FAIL: cout << "<" << S << "> is not acceptable.\n"; continue;
    }
}
