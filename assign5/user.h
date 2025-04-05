/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);

 // Destructor to clean up dynamic memory.
 ~User();

 // Copy constructor for deep copying another User.
 User(const User& other);

 // Copy assignment operator.
 User& operator=(const User& other);

 // Deleted move constructor and assignment (not allowed).
 User(User&& other) = delete;
 User& operator=(User&& other) = delete;

 // Overloaded += operator: adds mutual friendship.
 User& operator+=(User& other);

 // Overloaded < operator: compares users by name.
 bool operator<(const User& other) const;

 // Friend function to print user info to output stream.
 friend std::ostream& operator<<(std::ostream& os, const User& user);

private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};