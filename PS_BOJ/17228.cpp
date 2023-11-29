#include<bits/stdc++.h>
using namespace std;
int N;
pair<int,char> T[501010];
string S;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = N - 1; i; --i) {
        int a, b; char c;
        cin >> a >> b >> c;
        T[a] = {b, c};
    }
    cin >> S;
    cout << S;
    
}
