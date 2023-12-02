#include <iostream>
#include <limits>
#include "algorithms/BoyerMoore.hpp"
#include "algorithms/KnuthMorrisPratt.hpp"
#include "algorithms/RabinKarp.hpp"
#include "include/MultithreadedAlgorithms.hpp"

const std::string DEFAULT_FILENAME = "tests/test1017k.txt";
const std::string BIG_FILENAME = "tests/test2034k.txt";
const std::string LARGE_FILENAME = "tests/test6100k.txt";
const std::string MIDDLE_FILENAME = "tests/test770k.txt";
const std::string NORMAL_FILENAME = "tests/test390k.txt";
const std::string SMALL_FILENAME = "tests/test200k.txt";
const std::string DEFAULT_PATTERN = "qwerty";

const std::string MODE_PROMPT = "Choose mode: \n"
                                "For Manual mode enter letter M \n"
                                "For Automatic mode enter letter A \n"
                                "For Multithreading mode enter letter T \n";
const std::string MANUAL_PROMPT = "Enter the substring to search: ";
const std::string INVALID_MODE_ERROR = "Invalid mode selection.";

const int TEST_SMALL_FILE = 1;
const int TEST_NORMAL_FILE = 2;
const int TEST_MIDDLE_FILE = 3;
const int TEST_DEFAULT_FILE = 4;
const int TEST_BIG_FILE = 5;
const int TEST_LARGE_FILE = 6;


const std::string TEST_PROMPT = "Choose one of the tests:\n"
                                "For Testing Small File with 200.000 symbols enter 1 \n"
                                "For Testing Normal File with 390.000 symbols enter 2 \n"
                                "For Testing Middle File with 770.000 symbols enter 3 \n"
                                "For Testing Default File with 1.017.000 symbols enter 4 \n"
                                "For Testing Big File with 2.034.000 symbols enter 5 \n"
                                "For Testing Large File with 6.100.000 symbols enter 6 \n";

// Function to print a separator line
void printSeparator() {
    std::cout << "----------------------" << std::endl;
}

// Function to print help message
void printHelp() {
    std::cout << "Usage: alg [options]\n";

    std::cout << "Options:\n";
    std::cout << "  --help\tDisplay this help message.\n";
    std::cout << "  --version\tDisplay program version.\n\n";

    std::cout << "Description:\n";
    std::cout << "  This program helps to search for a substring within a string using different algorithms.\n";
    std::cout << "  Supported algorithms: Boyer-Moore, Knuth-Morris-Pratt, Rabin-Karp.\n\n";
    std::cout << "Manual Mode:\n";
    std::cout << "  Enter 'M' when prompted to choose a mode. Then enter the substring to search when prompted.\n";
    std::cout << "  The program will ask for the specific string to search within the text and perform the search.\n\n";

    std::cout << "Automatic Mode:\n";
    std::cout << "  Enter 'A' when prompted to choose a mode.\n";
    std::cout << "  The program will then prompt you to select a test file size "
                 "(small, normal, middle, default, big).\n";
    std::cout << "  After selecting the file size, the program will automatically perform tests "
                 "using the predefined pattern 'qwerty'.\n\n";

    std::cout << "Multithreading Mode:\n";
    std::cout << "  Enter 'T' when prompted to choose a mode.\n";
    std::cout << "  The program will then prompt you to select a test file size "
                 "(small, normal, middle, default, big).\n";
    std::cout << "  After selecting the file size, the program will automatically perform tests "
                 "using the predefined pattern 'qwerty'.\n\n";

    std::cout << "Usage from terminal:\n";

    std::cout << "  Navigate to the program directory:\n";
    std::cout << "  $ cd Desktop/pcc/pro/draft/alg/cmake-build-debug\n\n";

    std::cout << "  To build the program:\n" ;
    std::cout << "  $ mkdir cmake-build-debug && cd cmake-build-debug && cmake .. && make\n\n";

    std::cout << "  To run the program:\n";
    std::cout << "  $ ./alg\n\n" ;

    std::cout << "Program Menu:\n";

    std::cout << "  Choose mode: \n";
    std::cout << "  For Manual mode enter letter M \n";
    std::cout << "  For Automatic mode enter letter A \n";
    std::cout << "  For Multithreading mode enter letter T \n\n";

    std::cout << "  [Follow the prompts to select a file and search for a pattern]\n" ;

    std::cout << "  After launching, choose the mode by entering 'M' for Manual or 'A' for Automatic.\n\n";
    std::cout << "  In Manual mode, you will be asked to enter the pattern you want to search for.\n\n";

    std::cout << "  In Automatic and Multithreading modes, select the file size "
                 "to test the predefined pattern against different file sizes.\n";
    std::cout << "  Choose the test by entering '1' for Small File with 200.000 symbols\n";
    std::cout << "  Choose the test by entering '2' for Normal File with 390.000 symbols\n";
    std::cout << "  Choose the test by entering '3' for Middle File with 770.000 symbols\n";
    std::cout << "  Choose the test by entering '4' for Default File with 1.017.000 symbols\n";
    std::cout << "  Choose the test by entering '5' for Big File with 2.034.000 symbols\n";
    std::cout << "  Choose the test by entering '6' for Large File with 6.100.000 symbols\n\n";


    std::cout << "  The program will display the index(es) where the pattern is found and "
                 "the time taken for each algorithm.\n\n";

    std::cout << "Created by Aleksandr Kross © FEL-2023." << std::endl;
    exit(0);  // Exit the program after printing the help message
}


int main(int argc, char* argv[]) {

    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "--help") {
            printHelp();
        } else if (arg == "--version") {
            std::cout << "Version 1.0" << std::endl;
            exit(0);
        }
    }

    std::cout << MODE_PROMPT;

    std::string mode;
    std::cin >> mode;

    // Clear input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string filename = DEFAULT_FILENAME;
    std::string filenameBig = BIG_FILENAME;
    std::string filenameLarge = LARGE_FILENAME;
    std::string filenameMiddle = MIDDLE_FILENAME;
    std::string filenameNormal = NORMAL_FILENAME;
    std::string filenameSmall = SMALL_FILENAME;

    std::string pattern = DEFAULT_PATTERN;

    if (mode == "M" || mode == "m") {

        std::filesystem::current_path(std::filesystem::current_path().parent_path());

        // Manual mode
        std::cout << MANUAL_PROMPT;
        std::getline(std::cin, pattern);

        BoyerMoore bm;
        KnuthMorrisPratt kmp;
        RabinKarp rk;

        printSeparator();
        bm.searchInFileBM(filename, pattern);

        printSeparator();
        kmp.searchInFileKMP(filename, pattern);

        printSeparator();
        rk.searchInFileRK(filename, pattern, INT_MAX);
    } else if (mode == "A" || mode == "a") {

        std::filesystem::current_path(std::filesystem::current_path().parent_path());

        // Automatic mode
        int q = INT_MAX;

        int testNumber;
        std::cout << TEST_PROMPT;
        std::cin >> testNumber;

        BoyerMoore bm;
        KnuthMorrisPratt kmp;
        RabinKarp rk;

        switch (testNumber) {
            case TEST_SMALL_FILE:

                printSeparator();
                bm.searchInFileBM(filenameSmall, pattern);

                printSeparator();
                kmp.searchInFileKMP(filenameSmall, pattern);

                printSeparator();
                rk.searchInFileRK(filenameSmall, pattern, q);
                break;

            case TEST_NORMAL_FILE:

                printSeparator();
                bm.searchInFileBM(filenameNormal, pattern);

                printSeparator();
                kmp.searchInFileKMP(filenameNormal, pattern);

                printSeparator();
                rk.searchInFileRK(filenameNormal, pattern, q);
                break;

            case TEST_MIDDLE_FILE:

                printSeparator();
                bm.searchInFileBM(filenameMiddle, pattern);

                printSeparator();
                kmp.searchInFileKMP(filenameMiddle, pattern);

                printSeparator();
                rk.searchInFileRK(filenameMiddle, pattern, q);
                break;

            case TEST_DEFAULT_FILE:

                printSeparator();
                bm.searchInFileBM(filename, pattern);

                printSeparator();
                kmp.searchInFileKMP(filename, pattern);

                printSeparator();
                rk.searchInFileRK(filename, pattern, q);
                break;

            case TEST_BIG_FILE:

                printSeparator();
                bm.searchInFileBM(filenameBig, pattern);

                printSeparator();
                kmp.searchInFileKMP(filenameBig, pattern);

                printSeparator();
                rk.searchInFileRK(filenameBig, pattern, q);
                break;

            case TEST_LARGE_FILE:

                printSeparator();
                bm.searchInFileBM(filenameLarge, pattern);

                printSeparator();
                kmp.searchInFileKMP(filenameLarge, pattern);

                printSeparator();
                rk.searchInFileRK(filenameLarge, pattern, q);
                break;

            default:
                std::cerr << INVALID_MODE_ERROR << std::endl;
                break;
        }

    } else if (mode == "T" || mode == "t") {

        std::filesystem::current_path(std::filesystem::current_path().parent_path());

        // Multithreaded mode
        int testNumber;
        std::cout << TEST_PROMPT;
        std::cin >> testNumber;

        MultithreadedAlgorithms multithreadedAlgorithms;

        switch (testNumber) {
            case TEST_SMALL_FILE:
                multithreadedAlgorithms.runMultithreadedAlgorithms(SMALL_FILENAME, DEFAULT_PATTERN);
                break;
            case TEST_NORMAL_FILE:
                multithreadedAlgorithms.runMultithreadedAlgorithms(NORMAL_FILENAME, DEFAULT_PATTERN);
                break;
            case TEST_MIDDLE_FILE:
                multithreadedAlgorithms.runMultithreadedAlgorithms(MIDDLE_FILENAME, DEFAULT_PATTERN);
                break;
            case TEST_DEFAULT_FILE:
                multithreadedAlgorithms.runMultithreadedAlgorithms(DEFAULT_FILENAME, DEFAULT_PATTERN);
                break;
            case TEST_BIG_FILE:
                multithreadedAlgorithms.runMultithreadedAlgorithms(BIG_FILENAME, DEFAULT_PATTERN);
                break;
            case TEST_LARGE_FILE:
                multithreadedAlgorithms.runMultithreadedAlgorithms(LARGE_FILENAME, DEFAULT_PATTERN);
                break;
            default:
                std::cerr << INVALID_MODE_ERROR << std::endl;
                break;
        }

    } else {
        std::cerr << INVALID_MODE_ERROR << std::endl;
    }

    return 0;
}