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

int main() {
    //Provided by Bryan as a simple test, thank you.
    lab2::stringVector sample;//sample contains [] nothing
    sample.append(std::string("Example string"));//sample contains ["Example string"] 1 item
    std::cout << sample[0] << std::endl;
    sample.append(std::string("another Example"));//sample contains ["Example string","another Example"] 2 item
    std::cout << sample[1] << std::endl;
    sample.append(std::string("yet another"));//sample contains ["Example string","another Example", "yet another"] 3 item
    std::cout << sample[2] << std::endl;

    int n = 46;
    std::cout << fib_seq(n) << std::endl;


    return 0;
    // return 0;
}