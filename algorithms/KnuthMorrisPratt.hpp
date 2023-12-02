//
// Created by krossale on 2.12.23.
//

#ifndef OOP_KNUTHMORRISPRATT_HPP
#define OOP_KNUTHMORRISPRATT_HPP


#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>
#include <chrono>
#include <vector>

class KnuthMorrisPratt {
public:
    KnuthMorrisPratt();

    void searchInFileKMP(const std::string& filename, const std::string& pattern);

    void searchKnuthMorrisPratt(const char *pattern, const char *txt);

private:
    static void initializeLPSArray(char* pattern, int M, int* lps);
    static std::vector<int> computeLPSArray(char* pattern, int M);
};



#endif //OOP_KNUTHMORRISPRATT_HPP
