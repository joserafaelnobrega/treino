#include <iostream> // calcula o salario do mês tendo como base o numero de horas trabalhadas e valor da hora
#include <iomanip>

int main(){

    int numero_funcionario;  
    int hr_trabalhadas;
    double valor_hr;
 

    std::cin >> numero_funcionario;
    std::cin >> hr_trabalhadas;
    std::cin >> valor_hr;

    std::cout << std::fixed << std::setprecision(2); // ajusta a precisação das casas decimais

    std::cout << "NUMBER = " << numero_funcionario <<"\nSALARY = U$ "<< valor_hr*hr_trabalhadas << std::endl;




    return 0 ; 
}