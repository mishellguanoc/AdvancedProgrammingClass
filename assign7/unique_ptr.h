#pragma once

#include <cstddef>
#include <utility>
#include <stdexcept>

namespace cs106l {

template <typename T>
class unique_ptr {
private:
  T* ptr; // Pointer to the managed object

public:
  // Constructor from raw pointer
  unique_ptr(T* ptr) : ptr(ptr) {}

  // Constructor from nullptr
  unique_ptr(std::nullptr_t) : ptr(nullptr) {}

  // Default constructor
  unique_ptr() : ptr(nullptr) {}

  // Destructor - releases the owned memory
  ~unique_ptr() {
    delete ptr;
  }

  // Delete copy constructor
  unique_ptr(const unique_ptr& other) = delete;

  // Delete copy assignment
  unique_ptr& operator=(const unique_ptr& other) = delete;

  // Move constructor
  unique_ptr(unique_ptr&& other) : ptr(other.ptr) {
    other.ptr = nullptr;
  }

  // Move assignment operator
  unique_ptr& operator=(unique_ptr&& other) {
    if (this != &other) {
      delete ptr;
      ptr = other.ptr;
      other.ptr = nullptr;
    }
    return *this;
  }

  // Dereference operator
  T& operator*() {
    return *ptr;
  }

  const T& operator*() const {
    return *ptr;
  }

  // Arrow operator
  T* operator->() {
    return ptr;
  }

  const T* operator->() const {
    return ptr;
  }

  // Boolean conversion
  operator bool() const {
    return ptr != nullptr;
  }
};

// Helper to create a unique_ptr with constructor arguments
template <typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args) {
  return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

} // namespace cs106l
