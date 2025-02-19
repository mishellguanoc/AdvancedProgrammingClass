//
#include <cmath>
#include <iostream>
#include <utility>
int main(){
    int a, b, c;
    std::cout <<"Enter the coefficients of your equation"<< std::endl;
    // Ask for a, b, c.
    std::cout <<"a: ";
    std::cin >> a;
    std::cout <<"b: ";
    std::cin >> b;
    std::cout <<"c: "; 
    std::cin >> c;
    //there are solutions? true or false
    //determinant calculation
    double determinant = pow(b,2) - 4*a*c;
    if (determinant < 0){
        std::cout <<"There are not real solutions"<< std::endl;
        
    }
    else if(determinant == 0){
            double sol = (-b)/(2*a);
            std::cout <<"The only one solution is "<< sol << std::endl;
            
        }
        else{
            double sol1 = (-b + sqrt(determinant))/(2*a);
            double sol2 = (-b - sqrt(determinant))/(2*a);
            std::cout <<"The solutions are: "<< sol1 << " and " << sol2 << std::endl;
        }

    return 0;

}