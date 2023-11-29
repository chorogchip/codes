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

#include<map>
#include<queue>
int T, K, N;
char C;

int main() { FAST
    cin >> T;
    while (T--) {
priority_queue<int> Mq;
priority_queue<int,vector<int>,greater<int>> mq;
map<int,int> mp;
        cin >> K;
        while (K--) {
            cin >> C;
            if (C == 'I') {
                cin >> N;
                Mq.push(N); mq.push(N);
                auto it = mp.find(N);
                if (it != mp.end()) ++(it->second);
                else mp.insert(make_pair(N, 1));
            } else {
                cin >> N;
                if (mp.empty()) goto E;
                if (N == 1) {
                    E1:
                    int a = Mq.top(); Mq.pop();
                    auto it = mp.find(a);
                    if (it == mp.end()) goto E1;
                    if (it->second == 1) mp.erase(it);
                    else --(it->second);
                } else {
                    E2:
                    int a = mq.top(); mq.pop();
                    auto it = mp.find(a);
                    if (it == mp.end()) goto E2;
                    if (it->second == 1) mp.erase(it);
                    else --(it->second);

                } E:;
            }
        }
        if (mp.empty()) cout << "EMPTY\n";
        else {
            F1:
            int a = Mq.top(); Mq.pop();
            auto it = mp.find(a);
            if (it == mp.end()) goto F1;
            cout << it->first << " ";
            F2:
            a = mq.top(); mq.pop();
            it = mp.find(a);
            if (it == mp.end()) goto F2;
            cout << it->first << endl;
        }
    }
}
