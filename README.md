# :label: Semester Project for the Course Programming in C++ (PCC)

**Code**: B6B36PCC <br>
**Name**: Programming in C++/ Programování v C++ <br>
**Faculty**: Faculty of Electrical Engineering/ Fakulta elektrotechnická <br>
**Department**: 13136 - Department of Computer Science/ Katedra počítačů <br>

## :label: Assignment
<details><summary> Show more </summary>

**Description of the Task:**

The program is designed for substring search within a string using various algorithms. Supported algorithms: Boyer-Moore, Knuth-Morris-Pratt, Rabin-Karp.

**Description of Your Implementation:**

The program is written in C++ utilizing different substring search algorithms. Both manual and automatic modes of operation are implemented.

**Description of Functionality and Application Control:**

**Manual Mode:**
- When 'M' is selected, the user inputs the substring to search for.
- The program prompts for the text in which the search will be conducted.
- It performs the search and outputs the indices where the substring is found.

**Automatic Mode:**
- When 'A' is selected, the user chooses the size of the test file (small, normal, middle, default, big, large).
- The program conducts automated tests using the predefined pattern 'qwerty'.
- It displays the results and execution times for each algorithm.

**Multithreading Mode:**
- When 'T' is selected, the user chooses the size of the test file (small, normal, middle, default, big, large).
- The program conducts multithreading tests using the predefined pattern 'qwerty'.
- It displays the results and execution times for each algorithm.

**Results of Program Execution and Time Measurements Comparing Single-Threaded and Multi-Threaded Versions:**

[Results of tests and time measurements](https://docs.google.com/spreadsheets/d/1bQ4Q8Y8hrVNX3BBT0SBclzxHJxUccfTY/edit#gid=654834231)

</details>


## :label: Usage from the Command Line

**1.Navigate to the program directory:** <br>
`cd Desktop/pcc/pro/draft/alg/cmake-build-debug`<br>

**2.To build the program:** <br>
`mkdir cmake-build-debug && cd cmake-build-debug && cmake .. && make`<br>

**3.To run the program:** <br>
`./alg`

**4.To run the help:** <br>
`./alg --help`


## :label: Program Menu
<details><summary> Show more </summary>

**Choose the mode:**

For Manual mode, enter the letter **'M'**.<br>
For Automatic mode, enter the letter **'A'**.<br>
For Multithreading mode, enter the letter **'T'**.<br>
[Follow the prompts to select a file and search for a pattern]

**In Manual mode,** you will be asked to enter the pattern you want to search for.<br>

**In Automatic and Multithreading modes,** select the file size to test the predefined pattern against different file sizes.<br>
Choose the test by entering **'1'** for Small File with 200.000 symbols.<br>
Choose the test by entering **'2'** for Normal File with 390.000 symbols.<br>
Choose the test by entering **'3'** for Middle File with 770.000 symbols.<br>
Choose the test by entering **'4'** for Default File with 1.017.000 symbols.<br>
Choose the test by entering **'5'** for Big File with 2.034.000 symbols.<br>
Choose the test by entering **'6'** for Large File with 6.100.000 symbols.<br>


The program will display the index(es) where the pattern is found and the time taken for each algorithm.<br>

**Created by Aleksandr Kross © FEL-2023.**<br>

Feel free to modify the content as needed.
</details>

## :label: Documents

📝 **[Documentation-Link](https://docs.google.com/document/d/1Ic4lZro8YpQ0qKrQ4U2BBhNYikpH0ttu/)**

## :label: Contacts

**Teacher:** Ingrid Nagyová <br>

**Developer:** Aleksandr Kross  <br>
:email: **[If you have questions text me](mailto:krossale@fel.czut.cz)**
