#ifndef RK_H
#define RK_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <filesystem>
#include <chrono>
#include <climits>

int calculateHash(const char str[], int len, int q);
bool compareSubstring(const char pattern[], const char txt[], int start_index, int len_pat);
int updateHash(int hash_txt, const char txt[], int i, int len_pat, int h, int q);
std::vector<int> searchRabinKarp(const char pattern[], const char txt[], int q);
void searchInFileRK(const std::string& filename, const std::string& pattern, int q) ;

#endif // RK_H