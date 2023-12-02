//
// Created by krossale on 2.12.23.
//

#ifndef OOP_BOYERMOORE_HPP
#define OOP_BOYERMOORE_HPP


#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>
#include <chrono>
#include <vector>
#include <climits>


class BoyerMoore {
public:
    BoyerMoore();  // Конструктор

    void searchInFileBM(const std::string& filename, const std::string& pattern);

    void searchBoyerMoore(const std::string& pattern, const std::string& txt);

private:
    void constructFullBorderArray(int shift_arr[], int border_arr[], const std::string& pattern);
    void constructPartialBorderArray(int shift_arr[], int border_arr[], const std::string& pattern);
};


#endif //OOP_BOYERMOORE_HPP
