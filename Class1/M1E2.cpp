#include <iostream>

int main(){
    int callLength {0};
    bool cont {true};
    char rspt ;
    std::cout << "*****WELCOME*****" << std::endl;
    while (cont == true)
    {
    std::cout << "Input the lenght of the call:";
    std::cin >> callLength;

    std::cout << "The cost of the call was $" << callLength*10+12 <<"." << std::endl;

    std::cout << "Do you want to calculate the cost of another call? (Y/N)" << std::endl;
        std::cin >> rspt;

        if (rspt == 'N' || rspt == 'n') {
            cont = false;
        }
    }
    std::cout << "*****GOODBYE*****" << std::endl;
    return 0;
}