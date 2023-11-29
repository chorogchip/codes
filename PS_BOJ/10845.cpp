#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int N;

template<typename T, int sz>
class MyQueueueueue {
private:
    T arr_[sz + 1];
    int front_, rear_;
    T no_;
public:
    MyQueueueueue(T no): front_(0), rear_(0), no_(no) {}
    int size() {
        int ret = rear_ - front_;
        if (ret < 0) ret += sz + 1;
        return ret;
    }
    ~MyQueueueueue() {}
    bool empty() {
        return front_ == rear_;
    }
    void push(T data) {
        arr_[rear_++] = data;
        if (rear_ > sz) rear_ = 0;
    }
    T pop() {
        if (empty()) return no_;
        T temp = arr_[front_++];
        if (front_ > sz) front_ = 0; 
        return temp;
    }
    T front() {
        if (empty()) return no_;
        return arr_[front_];
    }
    T back() {
        if (empty()) return no_;
        int rearPos = rear_ - 1;
        if (rearPos < 0) rearPos += sz + 1;
        return arr_[rearPos];
    }
};

MAIN { FAST
    MyQueueueueue<int, 10001> queue(-1);
    string str;
    int num;
    cin >> N;
    foreach (i, N) {
        cin >> str;
        if (str == "push") {
            cin >> num;
            queue.push(num);
        } else if (str == "pop") cout << queue.pop() << endl;
        else if (str == "size") cout << queue.size() << endl;
        else if (str == "empty") cout << queue.empty() << endl;
        else if (str == "front") cout << queue.front() << endl;
        else if (str == "back") cout << queue.back() << endl;
    }
}