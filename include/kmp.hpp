#ifndef KMP_H
#define KMP_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <cstring>
#include <vector>


void initializeLPSArray(char* pattern, int M, int* lps);
std::vector<int> computeLPSArray(char* pattern, int M);
void searchKnuthMorrisPratt(char* pattern, char* txt);
void searchInFileKMP(const std::string& filename, const std::string& pattern);

#endif // KMP_H