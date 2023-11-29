#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
unordered_set<string> S;

int main() {
    int N, P; char c; cin >> N >> c;
    if (c == 'Y') P = 1;
    else if (c == 'F') P = 2;
    else P = 3;

    string str;
    str.reserve(21);
    int NN = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> str;
        if (S.find(str) == S.end()) {
            S.insert(str);
            ++NN;
        }
    }
    cout << NN/P;
}

