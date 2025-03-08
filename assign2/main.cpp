/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "MISHELL GUANO"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::set<std::string> applicants;
  std::ifstream file(filename);

  if (!file){
    std::cerr << "Error: Could not open the file " << filename << std::endl;
    return applicants; //return an empty set if the file could not be opened

  }
  std::string name;
  while (std::getline(file, name)){
    applicants.insert(name); //Insert the name in the set and will keep the alphabetic order
  }

  file.close();
  return applicants;

}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */


//Auxiliar functcion to obtain the initials of a name 
std::string get_initials(const std::string& name) {
  std::istringstream iss(name);
  std::string first, last;
  iss >> first >> last; // get the first and second name

  if (first.empty() || last.empty()) return "";
  return std::string(1, first[0]) + std::string(1, last[0]);
}


std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> matches;
  std::string target_initials = get_initials(name);

  for (const std::string& student : students) {
    if (get_initials(student) == target_initials) {
      matches.push(&student);
    }
  }

  return matches;

}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if(matches.empty()){
    return "NO MATCHES FOUND. ";
  }

  // Choose a match in a better way
  int count = matches.size();
  int randomIndex = rand() % count; // choose a random index

  for (int i=0; i < randomIndex; i++){
    matches.pop();
  }
  return *matches.front();


  
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
