#include <iostream>
#include <stringVector.h>

int fib_seq(int x){
    int list[100];
    list[0] = 0;
    list[1] = 1;
    for(int i=2; i<=x; i++){
        list[i] = list[i-1]+list[i-2];
    }

    return list[x];
}

void Sum(int a, int &b, int &c) {
    a = b + c;
    b = a + c;
    c = a + b;
    std::cout<< a << b << c;
}

int main() {
    int x = 15, y =3;
    Sum(x, y, y);
    std::cout << x << " " << y;
    return 0;


    return 0;
    // return 0;
}