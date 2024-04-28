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

    do {
        std::cout << "Ingresar el valor minimo (Debe ser menor al valor máximo): ";
        std::cin >> vMin;
        } while (vMin>vMax);
    vNumSecreto = rand() % (vMax-vMin+1)+vMin;

    std::cout << "EL NUMERO ES: " << vNumSecreto << std::endl;
    
    do{
        std::cout << "Ingresar la cantidad de intentos (No puede ser menor a 1): " ;
    std::cin >> intentosMaximos;
    }while (intentosMaximos<1);

    int aNumeros[intentosMaximos];

    while (intentos<intentosMaximos){
        std::cout << "\nTiene "<< intentosMaximos-intentos << " intento(s)- Ingresar un numero entre " << vMin << " y " << vMax << ": ";
        std::cin >> vNum;
        while(vNum > vMax || vNum < vMin){
            std::cout << "VALOR FUERA DE RANGO - Ingresar un numero entre " << vMin << " y " << vMax << ": ";
            std::cin >> vNum;
        }
        aNumeros[intentos] = vNum;

        if (vNum == vNumSecreto){
            intentos++;
            std::cout << "CORRECTO! El numero secreto era: " << vNumSecreto << " , utilizaste " << intentos << " intento(s)." << std::endl;
            intentos=0;
            break;
        }else if (vNum<vNumSecreto){
            intentos++;
            std::cout << "El número ingresado es menor al número secreto, utilizaste " << intentos << " intento(s). Los valores ingresaron fueron:" << std::endl;
            for (int i = 0; i < intentos;i++) {
            std::cout << aNumeros[i] << "  ";
            }
        }else{
            intentos++;
            std::cout << "El número ingresado es mayor al número secreto, utilizaste " << intentos << " intento(s). Los valores ingresaron fueron: " << std::endl;
            for (int i = 0; i < intentos;i++) {
            std::cout << aNumeros[i] << "  ";
            }
            }
        }
    if (intentos==intentosMaximos){
        std::cout << "\nTE QUEDASTE SIN INTENTOS. El número era " << vNumSecreto << "." << std::endl;
    }
    std::cout << "*****GRACIAS POR JUGAR*****" << std::endl;
    return 0;
}
