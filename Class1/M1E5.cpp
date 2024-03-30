#include <iostream>

int main(){
    int vA {0};
    int vB {0};
    int vC {0};
    int vAux {0};
    std::cout << "*****WELCOME*****" << std::endl;
    std::cout <<"Input three numbers: " << std::endl;
    std::cin >> vA >> vB >> vC;

    std::cout <<"Numbers input: " << vA <<","<< vB <<","<< vC << std::endl;

    vAux = vB;
    vB = vA+vC;
    vA = vC * 2;
    vC = vAux*3;

    std::cout <<"Numbers output: " << vA  <<" (double of C), "<< vB <<" (sum of A+C), "<< vC <<" (triple of B)." << std::endl;
    std::cout << "*****GOODBYE*****" << std::endl;
    return 0;
}