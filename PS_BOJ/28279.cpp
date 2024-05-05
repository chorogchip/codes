#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    deque<int> dq;
    while(n--) {
        int q; cin >> q;
        switch(q) {
            case 1: { int x; cin >> x; dq.push_front(x); } break;
            case 2: { int x; cin >> x; dq.push_back(x); } break;
            case 3: { if (dq.empty()) dq.push_back(-1); cout << dq.front() << '\n'; dq.pop_front(); } break;
            case 4: { if (dq.empty()) dq.push_back(-1); cout << dq.back() << '\n'; dq.pop_back(); } break;
            case 5: { cout << dq.size() << '\n'; } break;
            case 6: { cout << dq.empty() << '\n'; } break;
            case 7: { cout << (dq.empty() ? -1 : dq.front()) << '\n'; } break;
            case 8: { cout << (dq.empty() ? -1 : dq.back()) << '\n'; } break;
        }
    }
}