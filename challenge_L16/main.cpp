#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include "include/CLI/CLI.hpp"
#include <iomanip>
#include "include/barkeep-main/barkeep/barkeep.h"

bool is_valid_invoice(const std::string& invoice) {
    return !invoice.empty() && invoice[0] != 'C';
}

int main(int argc, char** argv) {
    CLI::App app{"Data Analytics CLI App"};

    std::string selected_country;
    app.add_option("--country", selected_country, "Filter transactions by country");
    bool only_uk = false;
    app.add_flag("--only-uk", only_uk, "Calculate total amount only for UK transactions");

    CLI11_PARSE(app, argc, argv);

   
    std::ifstream counter("online_retail.csv");
    size_t total_lines = 0;
    std::string tmp_line;
    while (std::getline(counter, tmp_line)) ++total_lines;
    counter.close();

    std::ifstream file("online_retail.csv");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file 'online_retail.csv'\n";
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip header

    namespace bk = barkeep;
    size_t current_line = 1;
    bk::ProgressBarConfig<size_t> config;
    config.total = total_lines;
    config.message = "Processing";
    config.style = bk::ProgressBarStyle::Bars;
    auto progress = bk::ProgressBar(&current_line, config);


    // Map of country -> unique invoice numbers
    std::unordered_map<std::string, std::unordered_set<std::string>> country_transactions;

    while (std::getline(file, line)) {
        ++current_line;

        std::stringstream ss(line);
        std::string invoice_no;
        std::getline(ss, invoice_no, ',');

        if (!is_valid_invoice(invoice_no))
            continue;

        size_t last_comma = line.rfind(',');
        if (last_comma == std::string::npos) continue;

        std::string country = line.substr(last_comma + 1);
        country.erase(country.find_last_not_of("\r\n") + 1);

        if (country.empty()) country = "Unknown";

        country_transactions[country].insert(invoice_no);
    }

    file.clear();
    file.seekg(0);
    std::getline(file, line); // skip header again
    current_line = 1;

    double total_amount = 0.0;

    while (std::getline(file, line)) {
        ++current_line;

        std::stringstream ss(line);
        std::string invoice_no, stock_code, description, quantity_str, invoice_date, unit_price_str, customer_id, country;

        std::getline(ss, invoice_no, ',');
        std::getline(ss, stock_code, ',');
        std::getline(ss, description, ',');
        std::getline(ss, quantity_str, ',');
        std::getline(ss, invoice_date, ',');
        std::getline(ss, unit_price_str, ',');
        std::getline(ss, customer_id, ',');
        std::getline(ss, country, ',');

        if (!is_valid_invoice(invoice_no))
            continue;

        int quantity = 0;
        double unit_price = 0.0;
        try {
            quantity = std::stoi(quantity_str);
            unit_price = std::stod(unit_price_str);
        } catch (...) {
            continue;
        }

        if (quantity <= 0)
            continue;

        if (only_uk && country != "United Kingdom")
            continue;

        total_amount += quantity * unit_price;
    }

    progress->done();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nTotal amount ";
    if (only_uk) std::cout << "for United Kingdom ";
    std::cout << "transactions: " << char(156) << " " << total_amount << "\n";

    file.close();

    if (!selected_country.empty()) {
        auto it = country_transactions.find(selected_country);
        if (it != country_transactions.end()) {
            std::cout << selected_country << ": " << it->second.size() << " transactions\n";
        } else {
            std::cout << selected_country << ": 0 transactions\n";
        }
    } else {
        std::cout << "Transactions per country:\n";
        for (const auto& [country, invoices] : country_transactions) {
            std::cout << "- " << country << ": " << invoices.size() << " transactions\n";
        }
    }

    return 0;
}
