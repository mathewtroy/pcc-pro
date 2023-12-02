
#include "MultithreadedAlgorithms.hpp"
#include <iostream>

MultithreadedAlgorithms::MultithreadedAlgorithms() {

}

/**
 * Run the Boyer-Moore algorithm for string search on a given file concurrently using multiple threads.
 *
 * @param filename The name of the file to search.
 * @param pattern The pattern to search for in the file.
 */
void MultithreadedAlgorithms::runBoyerMoore(const std::string& filename, const std::string& pattern) {
    BoyerMoore bm;
    bm.searchInFileBM(filename, pattern);
}

/**
 * Run the Knuth-Morris-Pratt algorithm for string search on a given file concurrently using multiple threads.
 *
 * @param filename The name of the file to search.
 * @param pattern The pattern to search for in the file.
 */
void MultithreadedAlgorithms::runKnuthMorrisPratt(const std::string& filename, const std::string& pattern) {
    KnuthMorrisPratt kmp;
    kmp.searchInFileKMP(filename, pattern);
}

/**
 * Run the Rabin-Karp algorithm for string search on a given file concurrently using multiple threads.
 *
 * @param filename The name of the file to search.
 * @param pattern The pattern to search for in the file.
 */
void MultithreadedAlgorithms::runRabinKarp(const std::string& filename, const std::string& pattern) {
    RabinKarp rk;
    rk.searchInFileRK(filename, pattern, INT_MAX);
}

/**
 * Run Boyer-Moore, Knuth-Morris-Pratt, and Rabin-Karp algorithms concurrently
 * on a given file using multiple threads.
 *
 * @param filename The name of the file to search.
 * @param pattern The pattern to search for in the file.
 */
void MultithreadedAlgorithms::runMultithreadedAlgorithms(const std::string& filename, const std::string& pattern) {
    // Run Boyer-Moore, Knuth-Morris-Pratt and Rabin-Karp concurrently using multiple threads
    std::thread bmThread(&MultithreadedAlgorithms::runBoyerMoore, this, filename, pattern);
    std::thread kmpThread(&MultithreadedAlgorithms::runKnuthMorrisPratt, this, filename, pattern);
    std::thread rkThread(&MultithreadedAlgorithms::runRabinKarp, this, filename, pattern);

    bmThread.join();
    kmpThread.join();
    rkThread.join();

}
