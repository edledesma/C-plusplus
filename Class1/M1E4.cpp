#include <iostream>

int main(){
    int v1 {0};
    int v2 {0};
    int v3 {0};
    int vA {0};
    std::cout << "*****WELCOME*****" << std::endl;
    std::cout <<"Input three numbers: " << std::endl;
    std::cin >> v1 >> v2 >> v3;

    std::cout <<"Numbers input: " << v1 <<","<< v2 <<","<< v3 << std::endl;

    vA = v1;
    v1 = v3;
    v3 = v2;
    v2 = vA;

    std::cout <<"Numbers output: " << v1 <<","<< v2 <<","<< v3 << std::endl;
    std::cout << "*****GOODBYE*****" << std::endl;
    return 0;
} 