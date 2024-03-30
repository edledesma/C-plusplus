#include <iostream>
#include <cmath>
#include <cctype>

void printMenu(){
    std::cout << "Input your desired operation: \n1: Sum\n2: Rest\n3: Multiplication\n4: Division\n5: Exit" << std::endl;
}

void printResult(double result){
    std::cout << "The result is " << result << std::endl;
}

int main() {
    char oper {'1'};
    double value1 {0}, value2 {0};
    double result {0};
    char cont {'Y'};

    std::cout << "*****WELCOME*****" << std::endl;
    while (cont == 'Y')
    {
        std:: cout << "Input first number: "<< "\n";
        std::cin >> value1;
        while(std::cin.fail()){ //Needed to check if the input is a valid double value
            std::cin.clear(); // Clear the error state. This prevents the endless duplication of the error msg
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // We discard the invalid input. Got this from StackOverflow, need to learn more about streamsize
            std::cout << "Invalid input. Please enter a valid number: ";
            std::cin >> value1;
        }
        
        std:: cout << "Input second number: "<< std::endl;
        std::cin >> value2;
        while(std::cin.fail()){ 
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number: ";
            std::cin >> value2;
        }

        printMenu();
        std::cin >> oper;

        while (oper != '1' && oper != '2' && oper != '3' && oper != '4' && oper != '5'){
            std::cout << "Invalid operation, please choose again (1-5)."<<std::endl;;
            printMenu();
            std::cin >> oper;
        }
        switch (oper){
            case '1':
                result = value1 + value2;
                printResult(result);
                break;
            case '2':
                result = value1 - value2;
                printResult(result);
                break;
            case '3':
                result = value1 * value2;
                printResult(result);
                break;
            case '4':
                if (value2 == 0){
                    std::cout <<"Can't divide by zero" << std::endl;
                }
                else{
                    result = value1 / value2;
                    printResult(result);
                } 
                break;
            case '5':
                std::cout << "*****GOODBYE*****" << std::endl;
                exit(0);
                break;
        }
        std::cout << "Do you wish to do another operation? (Y/N)"<< std::endl;
        std::cin >> cont;
        cont = (char) toupper(cont);
        
        while (cont != 'Y' && cont !='N')
        {
            std::cout <<"Invalid response - Only Y/N are valid"<< std::endl;
            std::cin >> cont;
            cont = (char) toupper(cont);
        }
        
        
    }
    std::cout << "*****GOODBYE*****" << std::endl;   
}