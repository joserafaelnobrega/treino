#include <iostream>
#include <iomanip>
int main(){

    double R; // valor do raio
    double A; // valor total da circuferencia

    std::cin >> R;

    A = R*R *3.14159; 
   std::cout << std::fixed << std::setprecision(4);

   std::cout << "A=" << A << std::endl;

    return 0 ;
}