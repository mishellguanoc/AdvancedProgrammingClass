// MoveSemanticsLab.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

/*
Part 1: Introduction to Copy vs. Move

Code Snippet:
*/

void part1_intro_copy_vs_move() {
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = v1;              // Copy
    std::vector<int> v3 = std::move(v1);   // Move

    std::cout << "v1 size: " << v1.size() << std::endl;
    std::cout << "v2 size: " << v2.size() << std::endl;
    std::cout << "v3 size: " << v3.size() << std::endl;

    /*
    Questions:

    • What is the output of this program?
      Output:
        v1 size: 0
        v2 size: 4
        v3 size: 4

    • Why does v1.size() return 0 after the move?
      Because its internal data was transferred to v3, leaving v1 in a valid but empty state.

    • What does std::move do?
      It casts an object to an rvalue reference to enable move semantics instead of copy.

    • Why is v1 still in a valid but unspecified state?
      Because C++ guarantees that after a move, the source object remains valid but its content is undefined.
    */
}

// Part 2: Implementing Move Semantics
class Buffer {
private:
    int* data;
    size_t size;

public:
    Buffer(size_t s) : size(s), data(new int[s]) {
        std::cout << "Constructor called\n";
    }

    ~Buffer() {
        delete[] data;
        std::cout << "Destructor called\n";
    }

    // Copy constructor
    Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
        std::cout << "Copy constructor called\n";
    }

    // Copy assignment
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
            std::cout << "Copy assignment called\n";
        }
        return *this;
    }

    // Move constructor
    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move constructor called\n";
    }

    // Move assignment
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move assignment called\n";
        }
        return *this;
    }
};

// Part 3: Using Your Class
void part3_using_buffer() {
    Buffer b1(100);
    Buffer b2 = b1;            // Copy constructor
    Buffer b3 = std::move(b1); // Move constructor

    Buffer b4(50);
    b4 = b2;                   // Copy assignment
    b4 = std::move(b2);        // Move assignment

    /*
    Questions:

    • What constructors and assignments are called and when?
      - b1(100) → regular constructor
      - b2 = b1 → copy constructor
      - b3 = std::move(b1) → move constructor
      - b4(50) → regular constructor
      - b4 = b2 → copy assignment
      - b4 = std::move(b2) → move assignment

    • What happens to the source object after a move?
      It is left in a valid but empty (unspecified) state.

    • What would happen if you didn’t define the move constructor/assignment?
      The default ones would be used, which might lead to inefficient copying or incorrect resource handling.
    */
}

// Part 4: Performance Comparison
void part4_performance() {
    auto start = std::chrono::high_resolution_clock::now();
    Buffer b1(10000000);
    Buffer b2 = b1; // Copy
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Copy Duration: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    start = std::chrono::high_resolution_clock::now();
    Buffer b3 = std::move(b2); // Move
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Move Duration: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";
}

// Part 5: Summary
void part5_summary() {
    std::cout << "\nSummary:\n";
    std::cout << "-Move semantics allow transferring ownership of resources efficiently,\n";
    std::cout << " avoiding unnecessary copies.\n\n";

    std::cout << "-They are particularly useful in projects involving heavy resource management,\n";
    std::cout << " such as large data processing, real-time systems, game engines, etc.\n\n";

    std::cout << "- Risks of using std::move incorrectly:\n";
    std::cout << "  -- Accessing a moved-from object without reinitializing it can lead to bugs.\n";
    std::cout << "  -- Misunderstanding std::move as performing the move itself (it only enables it).\n";
}

int main() {
    std::cout << "--- Part 1: Copy vs Move ---\n";
    part1_intro_copy_vs_move();

    std::cout << "\n--- Part 3: Using Buffer ---\n";
    part3_using_buffer();

    std::cout << "\n--- Part 4: Performance Comparison ---\n";
    part4_performance();

    std::cout << "\n--- Part 5: Summary ---\n";
    part5_summary();

    return 0;
}
