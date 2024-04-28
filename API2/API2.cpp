#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

int main () {
    setlocale(LC_ALL, "");
    srand(time(0));

    int intentos {0};
    int intentosMaximos;
    int vNum{0};
    int vNumSecreto;
    int vMax {0};
    int vMin {0};

    std::cout << "*****BIENVENIDO*****" << std::endl;
    std::cout << "Ingresar el valor maximo: ";
    std::cin >> vMax;
    std::cout << "Ingresar el valor minimo: ";
    std::cin >> vMin;
    while (vMin>vMax) {
        std::cout << "El valor minimo debe ser menor al valor maximo. Ingresar el valor minimo: ";
        std::cin >> vMin;
        }
    vNumSecreto = rand() % (vMax-vMin+1)+vMin;

    std::cout << "EL NUMERO ES: " << vNumSecreto << std::endl;
    std::cout << "Ingresar la cantidad de intentos: ";
    std::cin >> intentosMaximos;
    while (intentosMaximos<1){
        std::cout << "La cantidad de intentos no pude ser menor a 1. Ingresar la cantidad de intentos: " ;
    std::cin >> intentosMaximos;
    }

    while (intentos<intentosMaximos){
        std::cout << "Tiene "<< intentosMaximos-intentos << " intento(s)- Ingresar un numero entre " << vMin << " y " << vMax << ": ";
        std::cin >> vNum;
        while(vNum > vMax || vNum < vMin){
            std::cout << "VALOR FUERA DE RANGO - Ingresar un numero entre " << vMin << " y " << vMax << ": ";
            std::cin >> vNum;
        }

        if (vNum == vNumSecreto){
            intentos++;
            std::cout << "CORRECTO! El numero secreto era: " << vNumSecreto << " , utilizaste " << intentos << " intento(s)." << std::endl;
            break;
        }else if (vNum<vNumSecreto){
            intentos++;
            std::cout << "El número ingresado es menor al número secreto, utilizaste " << intentos << " intento(s)." << std::endl;
            
        }else{
            intentos++;
            std::cout << "El número ingresado es mayor al número secreto, utilizaste " << intentos << " intento(s)." << std::endl;
            }
        }
    if (intentos==intentosMaximos){
        std::cout << "TE QUEDASTE SIN INTENTOS. El número era " << vNumSecreto << "." << std::endl;
    }
    std::cout << "*****GRACIAS POR JUGAR*****" << std::endl;
    return 0;
}
