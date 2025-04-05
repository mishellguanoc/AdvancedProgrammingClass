#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}
/**
 * Destructor: releases the memory allocated for friends.
 */
User::~User() {
  delete[] _friends;
}

/**
 * Copy constructor: creates a deep copy of another User.
 * @param other The user to copy.
 */
User::User(const User& other)
  : _name(other._name)
  , _size(other._size)
  , _capacity(other._capacity)
{
  _friends = new std::string[_capacity];
  for (size_t i = 0; i < _size; ++i) {
    _friends[i] = other._friends[i];
  }
}

/**
 * Copy assignment operator: assigns one User to another.
 * @param other The user to assign from.
 * @return Reference to this user.
 */
User& User::operator=(const User& other) {
  if (this != &other) {
    delete[] _friends;

    _name = other._name;
    _size = other._size;
    _capacity = other._capacity;

    _friends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      _friends[i] = other._friends[i];
    }
  }
  return *this;
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/**
 * Stream output operator for User.
 * Prints the user's name and list of friends.
 */
std::ostream& operator<<(std::ostream& os, const User& user) {
  os << "User(name=" << user._name << ", friends=[";
  for (size_t i = 0; i < user._size; ++i) {
    if (i != 0) os << ", ";
    os << user._friends[i];
  }
  os << "])";
  return os;
}

/**
 * Overloaded += operator.
 * Adds the other user as a friend to this user,
 * and vice versa.
 * @param other The user to befriend.
 * @return Reference to this user.
 */
User& User::operator+=(User& other) {
  this->add_friend(other.get_name());
  other.add_friend(this->get_name());
  return *this;
}

/**
 * Overloaded < operator.
 * Compares users alphabetically by name.
 * @param other The user to compare with.
 * @return True if this user's name is less than the other's name.
 */
bool User::operator<(const User& other) const {
  return this->_name < other._name;
}
