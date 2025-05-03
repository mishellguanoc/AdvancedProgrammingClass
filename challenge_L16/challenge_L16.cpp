#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

int main(int argc, char* argv[]) {
    std::ifstream file("online_retail.csv");
    if (!file.is_open()) {
        std::cerr << "Couln't open the file\n";
        return 1;
    }

    std::unordered_map<std::string, int> countryTransactions;
    std::string line;


    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::string fields[8]; 
        int i = 0;

        
        while (std::getline(ss, cell, ',') && i < 8) {
            fields[i++] = cell;
        }

        if (i < 8) continue; 

        std::string country = fields[7];
        int quantity = 0;

        try {
            quantity = std::stoi(fields[3]);
        } catch (...) {
            continue; 
        }

        
        if (quantity > 0) {
            ++countryTransactions[country];
        } else {
            
            if (countryTransactions[country] > 0) {
                --countryTransactions[country];
            }
        }
    }

    file.close();

    if (argc == 2) {
        std::string inputCountry = argv[1];
        auto it = countryTransactions.find(inputCountry);
        if (it != countryTransactions.end()) {
            std::cout << inputCountry << ": " << it->second << " valid transactions\n";
        } else {
            std::cout << "There is no transactions for the country: " << inputCountry << "\n";
        }
    } else {
        for (const auto& [country, count] : countryTransactions) {
            std::cout << country << ": " << count << "  valid transactions\n";
        }
    }

    return 0;
}
