
// C++ Coding Challenge: Initialization, References, and Value Categories
#include <cmath>
#include <iostream>
#include <utility>
#include <tuple>
#include <string>


int main(){
//PART 1
    std::cout <<"Initial values"<<std::endl;
    //PART 1:Initialization
    int num1 = 10;
    double pi(3.14);
    auto saludo{"Hello"}; //uniform initialization
    float num{2.50}; //uniform initialization
    std::cout <<"int: "<< num1 << ", double: " << pi << ", string: " << saludo << ", float: " << num << std::endl <<std::endl;

//PART 2
    std::cout <<"Modified values"<<std::endl;
    //
    int& refInt = num1;
    refInt = 20;
    double& refDouble = pi;
    refDouble = 2.71;
    auto& refString = saludo;
    refString = "World";
    float& reFloat =num;
    reFloat = 1.50;
    std::cout <<"int: "<< num1 << ", double: " << pi << ", string: " << saludo << ", float: " << num << std::endl <<std::endl;
//PART 3
    std::cout <<"Pointer modification"<<std::endl;
    struct Point1 {
        int l, s, t;
    };

    Point1 q{5, 10, 15}; // initialization
    auto [l, s, t] = q; // structured Biding
    int& modified = l;
    modified = 100;
    std::cout << "int: " << l  << std::endl <<std::endl;



//PART 4
    std::cout <<"Structured Binding"<<std::endl ;
    struct Point {
        int x, y, z;
    };

    Point p{5, 10, 15}; // initialization
    auto [x, y, z] = p; // structured Biding
    std::cout << "x: " << x  <<  ", y: " << y  <<  ", z: " << x  << std::endl <<std::endl;

//PART 5
std::cout <<"Value Categories"<<std::endl ;

    int a = 42; // a is a l-value and 42 is a r-value
    int b = 10;
    int sum = a + b; // sum, a and b are l-value, (a + b) is r-value
    &a; // l-value,
    std::string c = "Hello"; //c is an l-value, "World" is an r-value, (c + " World") is an r-value
	std::string str = c + " World"; // str, c are l-values, (c + " World") is an r-value,
	int& refSum =sum; // l-value reference
	int&& rref = 100; // r-value reference
    
    return 0;

}