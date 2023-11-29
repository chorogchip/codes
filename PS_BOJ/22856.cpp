#include <iostream>
using namespace std;
int N, NN, A, B;
int V[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
    cin >> N; NN = N - 1 << 1;
    do {
        cin >> A;
        cin >> B >> V[A];
    } while (--N);
    A = V[1];
    while (A > 0) {
        A = V[A];
        --NN;
    }
    cout << NN;
}