
#include "KnuthMorrisPratt.hpp"

// Constants for informative messages
static const std::string KMP_INFO = "Knuth-Morris-Pratt Algorithm: Pattern found at index ";
const std::string TIME_TAKEN_KMP = "Time taken by function KMP: ";
const std::string MICROSECONDS_KMP = " microseconds";

// Error message for file opening failure
const std::string ERROR_OPENING_FILE_WITH_KMP = "Error opening file: ";

// Message for substring not found in the file
const std::string SUBSTRING_NOT_FOUND_WITH_KMP = "Substring not found in the file.";


KnuthMorrisPratt::KnuthMorrisPratt() {

}

/**
 * Initializes the Longest Proper Prefix which is also Suffix (LPS)
 * array for the Knuth-Morris-Pratt algorithm.
 *
 * @param pattern The pattern for which the LPS array is computed
 * @param M The length of the pattern
 * @param lps The array to store the computed LPS values
 */
void KnuthMorrisPratt::initializeLPSArray(char* pattern, int M, int* lps) {
    // Length of the previous longest proper prefix suffix
    int len = 0;

    // LPS value for the first character is always 0
    lps[0] = 0;
    int i = 1;

    // Loop to compute LPS values for the rest of the characters in the pattern
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {

            // If there was a mismatch
            if (len != 0) {

                // Update len based on the LPS values of previous characters
                len = lps[len - 1];
            } else {

                // If len is 0, set LPS value for the current character as 0 and move to the next character
                lps[i] = 0;
                i++;
            }
        }
    }
}


/**
 * Computes the Longest Proper Prefix which is also Suffix (LPS)
 * array for the Knuth-Morris-Pratt algorithm.
 *
 * @param pattern The pattern for which the LPS array is computed
 * @param M The length of the pattern
 * @return The computed LPS array
 */
std::vector<int> KnuthMorrisPratt::computeLPSArray(char* pattern, int M) {
    std::vector<int> lps(M, 0);
    initializeLPSArray(pattern, M, lps.data());
    return lps;
}


/**
 * Searches for a substring in a string using the Knuth-Morris-Pratt algorithm.
 *
 * @param pattern The pattern to search for
 * @param txt The text in which the pattern is searched
 */
void KnuthMorrisPratt::searchKnuthMorrisPratt(const char *pattern, const char *txt) {
    // Get the lengths of the pattern and the text
    int M = strlen((const char *) pattern);
    int N = strlen((const char *) txt);

    // Create an array to store the Longest Proper Prefix which is also Suffix (LPS) values
    std::vector<int> lps = computeLPSArray(const_cast<char *>(pattern), M);

    // Initialize variables for pattern and text indices
    int pattern_idx = 0;
    int j = 0; //text index

    // Variable to track if substring is found
    bool isFound = false;

    // Loop through the text
    while (pattern_idx < N) {

        // If characters match, move both pattern and text indices
        if (pattern[j] == txt[pattern_idx]) {
            j++;
            pattern_idx++;
        }

        // If the entire pattern is found in the text
        if (j == M) {
            std::cout << KMP_INFO << pattern_idx - j << std::endl;
            isFound = true;

            // Update the text index based on the LPS values
            j = lps[j - 1];

        } else if (pattern_idx < N && pattern[j] != txt[pattern_idx]) {
            if (j != 0) {

                // Update text index based on the LPS values
                j = lps[j - 1];
            } else {

                // Move to the next character in the text
                pattern_idx++;
            }
        }
    }

    // Print message if substring is not found
    if (!isFound) {
        std::cout << SUBSTRING_NOT_FOUND_WITH_KMP << std::endl;
    }
}


/**
 * Searches for a substring in a file using the Knuth-Morris-Pratt algorithm.
 *
 * @param filename The name of the file to search
 * @param pattern The pattern to search for in the file
 */
void KnuthMorrisPratt::searchInFileKMP(const std::string& filename, const std::string& pattern) {
// Open the file
    std::ifstream file(filename);

    // Check if the file is successfully opened
    if (!file.is_open()) {
        std::cerr << ERROR_OPENING_FILE_WITH_KMP << filename << std::endl;
        return;
    }

    // Read the content of the file into a string
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Measure time before execution
    auto start = std::chrono::high_resolution_clock::now();

    // Call the Knuth-Morris-Pratt algorithm to search for the pattern in the string
    searchKnuthMorrisPratt(const_cast<char*>(pattern.c_str()), const_cast<char*>(content.c_str()));

    // Measure time after execution
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    // Output the time taken by the Knuth-Morris-Pratt algorithm
    std::cout << TIME_TAKEN_KMP << duration.count() << MICROSECONDS_KMP << std::endl;

    // Close the file
    file.close();
}
