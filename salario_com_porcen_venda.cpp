#include <iostream> // calcula o salario de um vendendo quando ele recebe e uma porcentagem que ele ganha de acordo com o que vende
#include <iomanip>
#include <string>

int main(){


    std::string nome; 
    double salario;
    double valor_vendido;
 

    std::cin >> nome;
    std::cin >> salario;
    std::cin >> valor_vendido;

    std::cout << std::fixed <   < std::setprecision(2); // ajusta a precisação das casas decimais

    std::cout << "TOTAL = R$ "<< valor_vendido/  << std::endl;




    return 0 ; 
}