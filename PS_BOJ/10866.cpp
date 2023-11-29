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
class MyDequeueueue {
private:
    T arr_[sz + 1];
    int front_, back_;
    T no_;
public:
    MyDequeueueue(T no): front_(0), back_(0), no_(no) {}
    int size() {
        int ret = back_ - front_;
        if (ret < 0) ret += sz + 1;
        return ret;
    }
    ~MyDequeueueue() {}
    bool empty() {
        return front_ == back_;
    }
    void push_front(T data) {
        arr_[front_] = data;
        if (--front_ < 0) front_ = sz;
    }
    void push_back(T data) {
        if (++back_ > sz) back_ = 0;
        arr_[back_] = data;
    }
    T pop_front() {
        if (empty()) return no_;
        int frontPos = front_ + 1;
        if (frontPos > sz) frontPos -= sz + 1;
        T temp = arr_[frontPos];
        if (++front_ > sz) front_ = 0; 
        return temp;
    }
    T pop_back() {
        if (empty()) return no_;
        T temp = arr_[back_];
        if (--back_ < 0) back_ = sz;
        return temp;
    }
    T front() {
        if (empty()) return no_;
        int frontPos = front_ + 1;
        if (frontPos > sz) frontPos -= sz + 1;
        return arr_[frontPos];
    }
    T back() {
        if (empty()) return no_;
        return arr_[back_];
    }
};

MAIN { FAST
    MyDequeueueue<int, 10001> dequeue(-1);
    string str;
    int num;
    cin >> N;
    foreach (i, N) {
        cin >> str;
        if (str == "push_front") {
            cin >> num;
            dequeue.push_front(num);
        } else if (str == "push_back") {
            cin >> num;
            dequeue.push_back(num);
        }
        else if (str == "pop_front") cout << dequeue.pop_front() << endl;
        else if (str == "pop_back") cout << dequeue.pop_back() << endl;
        else if (str == "size") cout << dequeue.size() << endl;
        else if (str == "empty") cout << dequeue.empty() << endl;
        else if (str == "front") cout << dequeue.front() << endl;
        else if (str == "back") cout << dequeue.back() << endl;
    }
}