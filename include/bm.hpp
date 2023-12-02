#ifndef BM_H
#define BM_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <filesystem>
#include <chrono>
#include <climits>


void constructFullBorderArray(int shift_arr[], int border_arr[], const std::string& pattern);
void constructPartialBorderArray(int shift_arr[], int border_arr[], const std::string& pattern);
void searchBoyerMoore(const std::string& pattern, const std::string& txt);
void searchInFileBM(const std::string& filename, const std::string& pattern);

#endif // BM_H
