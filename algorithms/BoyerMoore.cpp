
#include "BoyerMoore.hpp"

// Constants for informative messages
static const std::string BM_INFO = "Boyer-Moore Algorithm: Pattern found at index ";
const std::string TIME_TAKEN_BM = "Time taken by function Boyer-Moore: ";
const std::string MICROSECONDS_BM = " microseconds";

// Error message for file opening failure
const std::string ERROR_OPENING_FILE_WITH_BM = "Error opening file: ";

// Message for substring not found in the file
const std::string SUBSTRING_NOT_FOUND_WITH_BM = "Substring not found in the file.";

BoyerMoore::BoyerMoore() {

}

/**
 * Constructs the full border array for the Boyer-Moore algorithm.
 *
 * @param shift_arr The shift array to be constructed
 * @param border_arr The border array to be constructed
 * @param pattern The pattern for which the arrays are constructed
 */
void BoyerMoore::constructFullBorderArray(int shift_arr[], int border_arr[], const std::string& pattern) {
    int n = pattern.size();
    int i = n;
    int j = n + 1;
    border_arr[i] = j;

    while (i > 0) {
        // Extend the border while characters match
        while (j <= n && pattern[i - 1] != pattern[j - 1]) {
            if (shift_arr[j] == 0)
                shift_arr[j] = j - i;
            j = border_arr[j];
        }

        // Move to the next position in the pattern
        i--;
        j--;
        border_arr[i] = j;
    }
}

/**
 * Constructs the partial border array for the Boyer-Moore algorithm.
 *
 * @param shift_arr The shift array to be constructed
 * @param border_arr The border array to be constructed
 * @param pattern The pattern for which the arrays are constructed
 */
void BoyerMoore::constructPartialBorderArray(int shift_arr[], int border_arr[], const std::string& pattern) {
    int n = pattern.size();
    int j = border_arr[0];

    for (int i = 0; i < n; i++) {

        // Update shift array and move j to the next position
        if (shift_arr[i] == 0)
            shift_arr[i] = j;
        if (i == j)
            j = border_arr[j];
    }
}

/**
 * Search for a pattern in a text using the Boyer-Moore algorithm.
 *
 * @param pattern The pattern to search for
 * @param txt The text to search in
 */
void BoyerMoore::searchBoyerMoore(const std::string& pattern, const std::string& txt) {
    int len_pat = pattern.size();
    int len_txt = txt.size();

    // Arrays for the Boyer-Moore algorithm
    int border_array[len_pat + 1];
    int shift_array[len_pat + 1];

    // Initialize the shift array with zeros
    for (int i = 0; i <= len_pat; i++) {
        shift_array[i] = 0;
    }

    // Construct the full and partial border arrays
    constructFullBorderArray(shift_array, border_array, pattern);
    constructPartialBorderArray(shift_array, border_array, pattern);

    int shift = 0;

    // Variable to track if substring is found
    bool isFound = false;

    while (shift <= (len_txt - len_pat)) {
        int j = len_pat - 1;

        // Compare pattern characters with text characters
        while (j >= 0 && pattern[j] == txt[shift + j]) {
            j--;
        }

        if (j < 0) {

            // Pattern found, print the index
            std::cout << BM_INFO << shift << std::endl;
            shift += shift_array[0];
            isFound = true;
        } else {

            // Update shift based on the bad character rule
            shift += shift_array[j + 1];
        }
    }

    // Print message if substring is not found
    if (!isFound) {
        std::cout << SUBSTRING_NOT_FOUND_WITH_BM << std::endl;
    }
}


/**
 * Search for a pattern in a file using the Boyer-Moore algorithm.
 *
 * @param filename The name of the file to search
 * @param pattern The pattern to search for in the file
 */
void BoyerMoore::searchInFileBM(const std::string& filename, const std::string& pattern) {
    // Open the file
    std::ifstream file(filename);

    // Check if the file is successfully opened
    if (!file.is_open()) {
        std::cerr << ERROR_OPENING_FILE_WITH_BM << filename << std::endl;
        return;
    }

    // Read the content of the file into a string
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Measure time before execution
    auto start = std::chrono::high_resolution_clock::now();

    // Call the Boyer-Moore algorithm to search for the pattern in the string
    searchBoyerMoore(pattern, content);

    // Measure time after execution
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    // Output the time taken by the Boyer-Moore algorithm
    std::cout << TIME_TAKEN_BM << duration.count() << MICROSECONDS_BM << std::endl;

    // Close the file
    file.close();
}

