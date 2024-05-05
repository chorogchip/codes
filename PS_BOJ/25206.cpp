#include<bits/stdc++.h>
using namespace std;

float score(string ss) {
    if (ss == "A+") return 4.5;
    if (ss == "A0") return 4.0;
    if (ss == "B+") return 3.5;
    if (ss == "B0") return 3.0;
    if (ss == "C+") return 2.5;
    if (ss == "C0") return 2.0;
    if (ss == "D+") return 1.5;
    if (ss == "D0") return 1.0;
    if (ss == "F") return 0.0;
    return 0.0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    float sum = 0;
    float asd = 0;
    for (int i = 0; i < 20; ++i) {
        string s; cin >> s;
        float f; cin >> f;
        string s2; cin >> s2;
        if (s2 == "P") continue;
        sum += f * score(s2);
        asd += f;
    }
    cout << sum / asd;
}