#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
   auto space_iters = find_all(source.begin(), source.end(), ::isspace);
  
    Corpus tokens;
    std::transform(
        space_iters.begin(), std::prev(space_iters.end()), 
        std::next(space_iters.begin()),                    
        std::inserter(tokens, tokens.end()),               
        [&source](auto start, auto end) {                  
            return Token(source, start, end);
        }
    );

    std::erase_if(tokens, [](const Token& t) {
        return t.content.empty();
    });

    return tokens;
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
    namespace rangeViews = std::ranges::views;

    auto results = source
        | rangeViews::filter([&dictionary](const Token& t) {
            return !dictionary.contains(t.content);
        })
    
        
        | rangeViews::transform([&dictionary](const Token& token) {
            auto suggestions = dictionary
                | rangeViews::filter([&token](const std::string& word) {
                    return levenshtein(token.content, word) == 1;
                })
                | rangeViews::common; 
            return Mispelling{
                token,
                std::set<std::string>(suggestions.begin(), suggestions.end())
            };
        })
        rangeViews::filter([](const Mispelling& x) {
            return !x.suggestions.empty();
        });

    return std::set<Mispelling>(results.begin(), results.end());
}

/* Helper methods */
#include "utils.cpp"