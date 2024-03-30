#include <iostream>

int main(){

    int hh {0};
    int mm {0};
    int ss {0};
    int ts {0};
    bool cont {true};
    char rspt;
    std::cout << "*****WELCOME*****" << std::endl;
    while (cont == true)
    {
        std::cout << "Input HOURS: ";
        std::cin >> hh;
        std::cout << "Input MINUTES: ";
        std::cin >> mm;
        std::cout << "Ingresar SECONDS: ";
        std::cin >> ss;

        ts = (hh * 60 * 60) + (mm * 60) + ss;

        std::cout << "Since 00:00 AM " << ts << " seconds went by."<< std::endl;

        std::cout << "Do you want to input another time? (Y/N)" << std::endl;
        std::cin >> rspt;

        if (rspt == 'N' || rspt == 'n') {
            cont = false;
        }
    }
    std::cout << "*****GOODBYE*****" << std::endl;
    return 0;
}