#include <iostream>
using namespace std;

//TASK 1.1: Write a Simple Template Function
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

//TASK 1.2: 
template <typename T>
T maxValue(T a, T b, T c) {
    return maxValue(a, maxValue(b, c));
}



int main() {
    auto pi = 3.141516;
    cout << maxValue(5, 10) << endl;          // Should print 10
    cout << maxValue(pi, 2.1) << endl;       // Should print 3.5
    cout << maxValue(string("apple"), string("orange")) << endl; // Should print "orange"
    cout << maxValue(string("parangaricutirimicuaro"),string("dog"), string("cat")) << endl;
    cout << maxValue(1, 5, 3) << endl;          // Should print 5
    cout << maxValue(2.1, 3.7, 1.9) << endl;    // Should print 3.7
}
