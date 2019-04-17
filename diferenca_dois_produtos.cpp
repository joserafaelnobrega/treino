#include <iostream> // da a diferença de dois produtos

int main(){

    int A;
    int B;
    int C;  
    int D;

    std::cin >> A;
    std::cin >> B;
    std::cin >> C;
    std::cin >> D;

    std::cout << "DIFERENCA = " << (A*B - C *D) << std::endl;


    return 0 ;
}