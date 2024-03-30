#include <iostream>
#include <cmath> // Import necessary to use the math library

int main() {
    double userBudget {0};
    const double priceYerba {850};
    const double priceAzucar {250};

    std::cout << "*****WELCOME*****" << std::endl;
    std:: cout << "Input the budget amount: $";
    std::cin >> userBudget;

    double budgetYerba {userBudget/2};
    double modYerba {std::fmod(budgetYerba,priceYerba)}; // We use fmod because modulo (%) only works with int types.
    std::cout << "The budget for Yerba is:  $" << budgetYerba <<". Enough to buy "<< std::trunc(budgetYerba/priceYerba) 
    << ((std::trunc(budgetYerba/priceYerba)==1)? " kg" : " kgs") << " of Yerba. with a budget surpluse of : $" << modYerba << std::endl;

    double budgetAzucar {userBudget/3};
    double modAzucar {std::fmod(budgetAzucar,priceAzucar)};
    std::cout << "The budget for Azucar is: $" << budgetAzucar << ". Enough to buy "<< std::trunc(budgetAzucar/priceAzucar) 
    << ((std::trunc(budgetAzucar/priceAzucar)==1)? " kg" : " kgs") <<" of Azucar with a budget surpluse of : $" << modAzucar << std::endl;

    double leftoverBudget {(userBudget - budgetYerba) - budgetAzucar};
    std::cout << "The amount of money left is: $" << leftoverBudget+modAzucar+modYerba << std::endl;

    std::cout << "*****GOODBYE*****" << std::endl;
    return 0;
}