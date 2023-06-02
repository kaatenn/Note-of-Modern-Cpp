//
// Created by 86137 on 2023/5/31.
//
#include "iostream"

using namespace std;

void f(int, int, int = 6);

void f(int, int = 5, int);

void f(int = 4, int, int);

void f(int a, int b, int c) { cout << a << ' ' << b << ' ' << c << endl; }

template<class T>
void print_args(T t) {
    cout << t << endl;
}

template<class ...T>
struct X {
    void f(int n = 0, T...t) {
        cout << n << endl;
        ((cout << t << " "), ...);
    }
};

template<class ...Args>
void f1(int x = 6, Args...args) {
    cout << x << endl;
    print_args(args...);
}

int main() {
    cout << "------Q1------" << endl;
    f();
    cout << "------Q2------" << endl;
    f1(1, 2); // 此处 1 是 x 而非后面的列表参数
    X<int, int>().f(1, 2, 3); // 此处 1 是 n 而非后面的列表参数
}