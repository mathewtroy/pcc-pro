//
// Created by krossale on 2.12.23.
//

#ifndef OOP_RABINKARP_HPP
#define OOP_RABINKARP_HPP


#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>
#include <chrono>
#include <vector>
#include <climits>


class RabinKarp {
public:
    RabinKarp();  // Конструктор

    void searchInFileRK(const std::string& filename, const std::string& pattern, int q);

    std::vector<int> searchRabinKarp(const char pattern[], const char txt[], int q);

private:
    int calculateHash(const char str[], int len, int q);
    bool compareSubstring(const char pattern[], const char txt[], int start_index, int len_pat);
    int updateHash(int hash_txt, const char txt[], int i, int len_pat, int h, int q);
};


#endif //OOP_RABINKARP_HPP


//
// Created by krossale on 2.12.23.
//

#ifndef OOP_RABINKARP_HPP
#define OOP_RABINKARP_HPP


#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>
#include <chrono>
#include <vector>
#include <climits>


class RabinKarp {
public:
    RabinKarp();  // Конструктор

    void searchInFileRK(const std::string& filename, const std::string& pattern, int q);

    std::vector<int> searchRabinKarp(const char pattern[], const char txt[], int q);

private:
    int calculateHash(const char str[], int len, int q);
    bool compareSubstring(const char pattern[], const char txt[], int start_index, int len_pat);
    int updateHash(int hash_txt, const char txt[], int i, int len_pat, int h, int q);
};


#endif //OOP_RABINKARP_HPP
