#include "../include/rk.hpp"


// Constants for informative messages
static const std::string RK_INFO = "Rabin-Karp Algorithm: Pattern found at index ";
const std::string TIME_TAKEN_RK = "Time taken by function Rabin-Karp: ";
const std::string MICROSECONDS_RK = " microseconds";

// Size of the alphabet (ASCII)
const static int ALPHABET_SIZE = 256;

// Error message for file opening failure
const std::string ERROR_OPENING_FILE_WITH_RK = "Error opening file: ";

// Message for substring not found in the file
const std::string SUBSTRING_NOT_FOUND_WITH_RK = "Substring not found in the file.";


/**
 * Calculates the hash value of a string modulo q.
 *
 * @param str The string for which to calculate the hash
 * @param len The length of the string
 * @param q The prime number used for hashing
 * @return The calculated hash value
 */
int calculateHash(const char str[], int len, int q) {
    int hash_value = 0;
    for (int i = 0; i < len; i++) {
        hash_value = (ALPHABET_SIZE * hash_value + str[i]) % q;
    }
    return hash_value;
}


/**
 * Compares the characters of the pattern and the text window without using an inner loop.
 *
 * @param pattern The pattern to search for
 * @param txt The text to search in
 * @param start_index The starting index in the text for the comparison
 * @param len_pat The length of the pattern
 * @return True if the characters match, false otherwise
 */
bool compareSubstring(const char pattern[], const char txt[], int start_index, int len_pat) {
    int j;
    for (j = 0; j < len_pat; j++) {
        if (txt[start_index + j] != pattern[j]) {
            break;
        }
    }
    return j == len_pat;
}

/**
 * Updates the text window hash efficiently without using an inner loop.
 *
 * @param hash_txt The current text window hash
 * @param txt The text to search in
 * @param i The current index in the text
 * @param len_pat The length of the pattern
 * @param h Precomputed value of (ALPHABET_SIZE^len_pat-1) % q
 * @param q The prime number used for hashing
 * @return The updated text window hash
 */
int updateHash(int hash_txt, const char txt[], int i, int len_pat, int h, int q) {
    // Update hash value efficiently without using an inner loop
    hash_txt = (ALPHABET_SIZE * (hash_txt - txt[i] * h) + txt[i + len_pat]) % q;

    if (hash_txt < 0)
        hash_txt = (hash_txt + q);

    return hash_txt;
}

/**
 * Performs Rabin-Karp search for a pattern in a text.
 *
 * @param pattern The pattern to search for
 * @param txt The text to search in
 * @param q The prime number used for hashing in Rabin-Karp algorithm
 * @return A vector containing the indices where the pattern is found in the text
 */
std::vector<int> searchRabinKarp(const char pattern[], const char txt[], int q) {
    std::vector<int> indices;
    int len_pat = strlen(pattern);
    int len_txt = strlen(txt);

    // Calculate the initial hash values for the pattern and the first window of text
    int hash_pat = calculateHash(pattern, len_pat, q);
    int hash_txt = calculateHash(txt, len_pat, q);

    // Precompute the value of (ALPHABET_SIZE^len_pat-1) % q efficiently
    int h = 1;
    for (int i = 0; i < len_pat - 1; i++)
        h = (h * ALPHABET_SIZE) % q;

    // Find the match
    for (int i = 0; i <= len_txt - len_pat; i++) {
        if (hash_pat == hash_txt && compareSubstring(pattern, txt, i, len_pat)) {
            indices.push_back(i);
        }

        if (i < len_txt - len_pat) {
            hash_txt = updateHash(hash_txt, txt, i, len_pat, h, q);
        }
    }

    return indices;
}




/**
 * Function to search for a pattern in a file using the Rabin-Karp algorithm
 *
 * @param filename The name of the file to search
 * @param pattern The pattern to search for in the file
 * @param q The prime number used for hashing in Rabin-Karp algorithm
 */
void searchInFileRK(const std::string& filename, const std::string& pattern, int q) {
    // Open the file
    std::ifstream file(filename);

    // Check if the file is successfully opened
    if (!file.is_open()) {
        std::cerr << ERROR_OPENING_FILE_WITH_RK << filename << std::endl;
        return;
    }

    // Read the content of the file into a string
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    const char* txt = content.c_str();

    // Measure time before execution
    auto start = std::chrono::high_resolution_clock::now();

    // Call the Rabin-Karp algorithm to search for the pattern in the string
    std::vector<int> indices = searchRabinKarp(pattern.c_str(), txt, q);

    // Measure time after execution
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    // Variable to track if substring is found
    bool isFound = false;

    // Output the found indices
    for (int index : indices) {
        std::cout << RK_INFO << index << std::endl;
        isFound = true;
    }

    // Print message if substring is not found
    if (!isFound) {
        std::cout << SUBSTRING_NOT_FOUND_WITH_RK << std::endl;
    }

    // Output the time taken by the Rabin-Karp algorithm
    std::cout << TIME_TAKEN_RK << duration.count() << MICROSECONDS_RK << std::endl;

    // Close the file
    file.close();
}
