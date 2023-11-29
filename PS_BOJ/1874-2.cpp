#include<cstdio>

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
    MyStack(const MyStack&) = delete;
    MyStack operator=(const MyStack&) = delete;
    inline void push(int data) {
        data_[size_] = data;
        size_++;
    }
    inline int pop() {
        if (size_ == 0) {
            return -1;
        }
        size_--;
        return data_[size_];
    }
    inline int top() const {
        if (size_ == 0) {
            return -1;
        }
        return data_[size_ - 1];
    }
    inline int size() const {
        return size_;
    }
    inline int empty() const {
        return size_ == 0;
    }
};

// 따로 입력 함수 사용
int getInt() {
    char c;
    int num = 0;
    while((c = getchar()) != '\n') {
        num *= 10;
        num += (c - '0');
    }
    return num;
}

char arr[400001], *p = arr;
int n, num, pnum = 0;  // pnum 은 마지막으로 스택에 넣은 수

int main(void) {
    scanf("%d", &n);
    getchar();
    MyStack stack(n);
    for (int i = 0; i != n; ++i) {
        num = getInt();
        if (num > stack.top()) {
            // num 전까지 넣음
            for(int j = pnum + 1; j < num; j++) {
                stack.push(j);
                *(p++) = '+';
                *(p++) = '\n';
            }
            pnum = num;
            // num을 넣었다가 뺌
            *(p++) = '+';
            *(p++) = '\n';
            *(p++) = '-';
            *(p++) = '\n';
        } else {
            if (stack.pop() == num) {
                // 마지막에 넣은걸 뺌
                *(p++) = '-';
                *(p++) = '\n';
            } else {
                // 마지막에 넣은게 엉뚱한 수면 불가능
                fwrite("NO\n", 1, 3, stdout);
                return 0;
            }
        }
    }

    fwrite(arr, 1, n << 2, stdout);
}