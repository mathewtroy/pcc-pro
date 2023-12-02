cmake_minimum_required(VERSION 3.22)
project(alg)

set(CMAKE_CXX_STANDARD 17)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(alg main.cpp
        algorithms/BoyerMoore.cpp
        algorithms/KnuthMorrisPratt.cpp
        algorithms/RabinKarp.cpp
        algorithms/KnuthMorrisPratt.cpp
        include/MultithreadedAlgorithms.cpp

)

target_link_libraries(alg Threads::Threads)
