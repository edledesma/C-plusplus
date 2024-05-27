#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <algorithm>

const int MAX_NUMEROS = 100;

bool numerosYaIngresados(const int numeros[], int vNum, int size) {
    for (int i = 0; i < size; ++i) {
        if (numeros[i] == vNum) {
            return true;
        }
    }
    return false;
}

void mostrarNumeros(const int numeros[], int size) {
    std::cout << "Numeros previos: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;
}

void ordenarNumeros(int numeros[], int size) {
    std::sort(numeros, numeros + size);
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(0));

    int intentos{ 0 };
    int intentosMaximos{0};
    int vNum{ 0 };
    int vNumSecreto;
    int vMax{ 0 };
    int vMin{ 0 };
    int numeros_ingresados[MAX_NUMEROS];
    int numeros_ingresados_size = 0;


    std::cout << "*****BIENVENIDO*****" << std::endl;

    std::cout << "Ingresar el valor maximo: ";
    std::cin >> vMax;

    do {
        std::cout << "Ingresar el valor minimo (Debe ser menor al valor máximo): ";
        std::cin >> vMin;
    } while (vMin > vMax);
    vNumSecreto = rand() % (vMax - vMin + 1) + vMin;

    //std::cout << "EL NUMERO ES: " << vNumSecreto << std::endl; DEBUG - Esto es para mostrar el número secreto.

    do {
        std::cout << "Ingresar la cantidad de intentos (No puede ser menor a 1 ni mayor a 100): ";
        std::cin >> intentosMaximos;
    } while (intentosMaximos < 1 || intentosMaximos > 100);

    
    while (intentos < intentosMaximos) {
        std::cout << "\nTiene " << intentosMaximos - intentos << " intento(s)- Ingresar un numero entre " << vMin << " y " << vMax << ": ";
        std::cin >> vNum;

        if (vNum < vMin || vNum > vMax) {
            std::cout << "El valor ingresado esta fuera del rango. Ingresar un numero entre " << vMin << " y " << vMax << ": ";
            continue;
        }

        if (numerosYaIngresados(numeros_ingresados, vNum, numeros_ingresados_size)) {
            std::cout << "El valor ingresado ya ha sido ingresado previamente. Ingresar otro numero ";
            continue;
        }

        numeros_ingresados[numeros_ingresados_size++] = vNum;

        ordenarNumeros(numeros_ingresados, numeros_ingresados_size);

        while (vNum > vMax || vNum < vMin) {
            std::cout << "VALOR FUERA DE RANGO - Ingresar un numero entre " << vMin << " y " << vMax << ": ";
            std::cin >> vNum;
        }
        
        if (vNum == vNumSecreto) {
            intentos++;
            std::cout << "CORRECTO! El numero secreto era: " << vNumSecreto << " , utilizaste " << intentos << " intento(s)." << std::endl;
            intentos = 0;
            break;
        }
        else {
            std::cout << "Número incorrecto.";

            if (vNum < vNumSecreto) {
                std::cout << "El número es mayor." << std::endl;
            }
            else {
                std::cout << "El número es menor." << std::endl;
            }

            mostrarNumeros(numeros_ingresados, numeros_ingresados_size);
            intentos++;
            std::cout << "Te quedan " << (intentosMaximos - intentos) << " intentos." << std::endl;
        }
    }
    if (intentos == intentosMaximos) {
        std::cout << "TE QUEDASTE SIN INTENTOS. El número era " << vNumSecreto << "." << std::endl;
    }
    std::cout << "*****GRACIAS POR JUGAR*****" << std::endl;
    return 0;
}
