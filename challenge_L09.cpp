#include <iostream>
#include <concepts>
using namespace std;

// TASK 1.1: Write a Simple Template Function
// Returns the maximum value between two given parameters of the same type
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// TASK 1.2: Overload maxValue to accept three parameters
// Returns the maximum value among three given parameters
template <typename T>
T maxValue(T a, T b, T c) {
    return maxValue(a, maxValue(b, c));
}

// TASK 2.1: Create a Template with a Concept
// Concept Numeric allows only integral or floating-point types
template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

// add function that only works with numeric types
template <Numeric T>
T add(T a, T b) {
    return a + b;
}

// TASK 3.1: Write a Variadic Template Function
// Recursively prints all arguments separated by spaces
template <typename T>
void printAll(T t) {
    cout << t << endl;
}

template <typename T, typename... Args>
void printAll(T t, Args... args) {
    cout << t << " ";
    printAll(args...);
}

// TASK 3.2: Variadic Template for Summation
// Returns the sum of all given arguments
template <typename T>
T sum(T t) {
    return t;
}

template <typename T, typename... Args>
T sum(T t, Args... args) {
    return t + sum(args...);
}

// TASK 4.1: Compile-Time Factorial Using Templates
// Computes factorial of N at compile-time
template <int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

// Base case for Factorial<0>
template <>
struct Factorial<0> {
    static constexpr int value = 1;
};

// TASK 4.2: Fibonacci Series Using Template Metaprogramming
// Computes the nth Fibonacci number at compile-time
template <int N>
struct Fibonacci {
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

// Base cases for Fibonacci sequence
template <>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr int value = 1;
};

int main() {
    auto pi = 3.141516;

    // Testing maxValue function
    cout << maxValue(5, 10) << endl;          // Should print 10
    cout << maxValue(pi, 2.1) << endl;        // Should print 3.141516
    cout << maxValue(string("apple"), string("orange")) << endl; // Should print "orange"
    cout << maxValue(string("parangaricutirimicuaro"), string("dog"), string("cat")) << endl; // Should print "parangaricutirimicuaro"
    cout << maxValue(1, 5, 3) << endl;        // Should print 5
    cout << maxValue(2.1, 3.7, 1.9) << endl;  // Should print 3.7

    // Additional test cases for maxValue
    cout << maxValue(42, 42) << endl;         // Should print 42 (same values)
    cout << maxValue(3.5, 3.5) << endl;       // Should print 3.5 (same values)
    cout << maxValue(string("short"), string("longer")) << endl; // Should print "longer"

    // Testing add function
    cout << add(3, 4) << endl;       // Should print 7
    cout << add(2.5, 3.1) << endl;   // Should print 5.6
    cout << add(7, 12) << endl;      // Should print 19
    cout << add(1.0, 2.0) << endl;   // Should print 3.0

    // Testing printAll function
    printAll(1, 2.5, "Hello", 'c'); // Should print: 1 2.5 Hello c
    printAll(10, 20, 30, 40, 50);   // Should print: 10 20 30 40 50
    printAll("This", "is", "a", "test"); // Should print: This is a test
    printAll("Just", 100, 1.23, 'A', "More", "Examples"); // Should print: Just 100 1.23 A More Examples

    // Testing sum function
    cout << sum(1, 2, 3, 4, 5) << endl;    // Should print 15
    cout << sum(1.1, 2.2, 3.3) << endl;    // Should print 6.6
    cout << sum(10, 20) << endl;           // Should print 30
    cout << sum(5.5, 6.5, 7.5) << endl;    // Should print 19.5

    // Testing compile-time Factorial
    constexpr int factResult = Factorial<5>::value;
    cout << factResult << endl;  // Should print 120

    // Testing compile-time Fibonacci
    constexpr int fibResult = Fibonacci<10>::value;
    cout << fibResult << endl;   // Should print 55

    // Additional tests for Factorial and Fibonacci
    constexpr int factResultLarge = Factorial<6>::value;
    cout << factResultLarge << endl;  // Should print 720

    constexpr int fibResultSmall = Fibonacci<5>::value;
    cout << fibResultSmall << endl;  // Should print 5

    return 0;
}
