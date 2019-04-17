#include <iostream> // media ponderada
#include <iomanip>

int main(){

    double A; //numero 1 
    double B; // numero 2
    double C; // numero 3
    double MEDIA; // divisão entre dois 

    std::cin >> A;
    std::cin >> B;
    std::cin >> C;

    MEDIA = (A*2 + B*3+ C*5)/10; // media ponderada

    std::cout << std::fixed << std::setprecision(1); // ajusta a precisação para 1 casa decimal

    std::cout << "MEDIA = " << MEDIA << std::endl;




    return 0 ; 
}