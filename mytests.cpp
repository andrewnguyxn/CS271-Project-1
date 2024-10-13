//==============================================================
// Names: Huy Phan, Tri Dang, Andrew Nguyen
// Class: CS 271-01
// Date:10/13/2024
// About: mytests.cpp contains the test cases of each function
// from sorting.cpp.
//==============================================================

#include <iostream>
using namespace std;

// Forward declarations of the test functions
bool test_insertion_sort();
bool test_merge_sort();
bool test_quicksort();
bool test_improved_quicksort();
bool test_randomized_quicksort();

int main() {
    int passed = 0, failed = 0;

    if (test_insertion_sort()) passed++; else failed++;
    if (test_merge_sort()) passed++; else failed++;
    if (test_quicksort()) passed++; else failed++;
    if (test_improved_quicksort()) passed++; else failed++;
    if (test_randomized_quicksort()) passed++; else failed++;

    // Output final test results
    cout << "Tests passed: " << passed << endl;
    cout << "Tests failed: " << failed << endl;

    return 0;
}
