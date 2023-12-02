cmake_minimum_required(VERSION 3.22)
project(alg)

set(CMAKE_CXX_STANDARD 17)

add_executable(alg src/main.cpp
        src/bm.cpp
        src/kmp.cpp
        src/rk.cpp
        include/kmp.hpp
        include/bm.hpp
        include/rk.hpp

)
