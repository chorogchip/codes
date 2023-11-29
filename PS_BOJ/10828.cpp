#include<cstdio>
#include<string.h>

class MyStack {

private:
    int* data_;
    int size_;

public:
    MyStack(int sz): size_(0) {
        data_ = new int[sz];
    }
    ~MyStack() {
        delete[] data_;
    }
    void push(int data) {
        data_[size_] = data;
        size_++;
    }
    void pop() {
        if (size_ == 0) {
            printf("-1\n");
            return;
        }
        size_--;
        printf("%d\n", data_[size_]);
    }
    void top() {
        if (size_ == 0) {
            printf("-1\n");
            return;
        }
        printf("%d\n", data_[size_ - 1]);
    }
    void size() {
        printf("%d\n", size_);
    }
    void empty() {
        printf("%d\n", size_ == 0);
    }
};

int main(void) {

    int n;
    scanf("%d", &n);

    MyStack ms(n);

    for (int i = 0; i != n; ++i) {

        char arr[10];
        scanf("%s", arr);
        
        if (strcmp(arr, "push") == 0) {
            int a;
            scanf("%d", &a);
            ms.push(a);
        } else if (strcmp(arr, "pop") == 0) {
            ms.pop();
        } else if (strcmp(arr, "size") == 0) {
            ms.size();
        } else if (strcmp(arr, "top") == 0) {
            ms.top();
        } else if (strcmp(arr, "empty") == 0) {
            ms.empty();
        } else {
            printf("error\n");
        }
    }
    
    return 0;
}