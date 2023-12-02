
#ifndef OOP_MULTITHREADEDALGORITHMS_HPP
#define OOP_MULTITHREADEDALGORITHMS_HPP

#include "../algorithms/BoyerMoore.hpp"
#include "../algorithms/KnuthMorrisPratt.hpp"
#include "../algorithms/RabinKarp.hpp"

#include <thread>

class MultithreadedAlgorithms {
public:
    MultithreadedAlgorithms();

    void runMultithreadedAlgorithms(const std::string& filename, const std::string& pattern);

private:
    void runBoyerMoore(const std::string& filename, const std::string& pattern);
    void runKnuthMorrisPratt(const std::string& filename, const std::string& pattern);
    void runRabinKarp(const std::string& filename, const std::string& pattern);

};

#endif // OOP_MULTITHREADEDALGORITHMS_HPP
