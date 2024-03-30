#include <iostream>
#include <string>

int main() {
    int age {0};
    std::string name;

    std::cout <<"Input your name: "<< std::endl;
    std::getline(std::cin,name); //When we have an input with a whitespace character we need to use getline() and then we can use cin.

    std::cout << "Input your age: "<< std::endl;
    std::cin >> age;

    std::cout << "Welcome, " << name << ", you were born in " << 2024-age << std::endl;

    return 0;
} 