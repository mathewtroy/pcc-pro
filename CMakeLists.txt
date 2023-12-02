cmake_minimum_required(VERSION 3.22)
project(alg)

set(CMAKE_CXX_STANDARD 17)

add_executable(alg main.cpp
        algorithms/BoyerMoore.cpp
        algorithms/KnuthMorrisPratt.cpp
        algorithms/RabinKarp.cpp
        algorithms/KnuthMorrisPratt.cpp
        include/MultithreadedAlgorithms.cpp

)
