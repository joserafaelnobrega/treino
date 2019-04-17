#include <iostream> // media ponderada
#include <iomanip>

int main(){

    double A; //numero 1 
    double B; // numero 2
    double MEDIA; // divisão entre dois 

    std::cin >> A;
    std::cin >> B;

    MEDIA = (A*3.5 + B*7.5)/11; // media ponderada

    std::cout << std::fixed << std::setprecision(5); // ajusta a precisação para 5 casas decimais

    std::cout << "MEDIA = " << MEDIA << std::endl;




    return 0 ; 
}