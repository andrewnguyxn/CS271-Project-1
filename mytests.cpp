//==============================================================
// Names: Huy Phan, Tri Dang, Andrew Nguyen
// Class: CS 271-01
// Date:10/13/2024
// About: mytests.cpp contains the test cases of each function
// from sorting.cpp.
//==============================================================

#include <iostream>
#include "sorting.cpp"
using namespace std;

// ==============================================================
// Huy Phan
// Print out the sorted array
//==============================================================
template <typename T>
void print_output(T* arr, long n, const string& test_name) {
    cout << test_name << endl;
    cout << "Sorted array: ";
    for (long i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ==============================================================
// Huy Phan
// verify array match output
//==============================================================
template <typename T>
bool verify(T* arr, long n, T* expected, const string& test_name) {
    for (long i = 0; i < n; i++) {
        if (arr[i] != expected[i]) {
            cout << test_name << " failed at index " << i << ": expected " << expected[i]
                 << " but got " << arr[i] << endl;
            return false;
        }
    }
    return true;
}

// ==============================================================
// INSERTION SORT
//==============================================================

// ==============================================================
// Huy Phan
// Test the insertion_sort method on regular case
//==============================================================
bool test_insertion_sort_regular() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 5, 7, 8, 9, 10};

    insertion_sort(arr, n);
    print_output(arr, n, "Insertion Sort Test 1: Regular Case");
    return verify(arr, n, expected, "Insertion Sort Test 1: Regular Case");
}

// ==============================================================
// Huy Phan
// Test the insertion_sort method on duplicate case
//==============================================================
bool test_insertion_sort_duplicates() {
    int arr[] = {4, 1, 3, 1, 2, 4};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 1, 2, 3, 4, 4};

    insertion_sort(arr, n);
    print_output(arr, n, "Insertion Sort Test 2: Duplicates");
    return verify(arr, n, expected, "Insertion Sort Test 2: Duplicates");
}

// ==============================================================
// Huy Phan
// Test the insertion_sort method on character case
//==============================================================
bool test_insertion_sort_characters() {
    char arr[] = {'d', 'b', 'a', 'c', 'e'};
    long n = sizeof(arr) / sizeof(arr[0]);
    char expected[] = {'a', 'b', 'c', 'd', 'e'};

    insertion_sort(arr, n);
    print_output(arr, n, "Insertion Sort Test 3: Characters");
    return verify(arr, n, expected, "Insertion Sort Test 3: Characters");
}

// ==============================================================
// Huy Phan
// Test the insertion_sort method on already sorted case
//==============================================================
bool test_insertion_sort_already_sorted() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 2, 3, 4, 5, 6};

    insertion_sort(arr, n);
    print_output(arr, n, "Insertion Sort Test 4: Already Sorted");
    return verify(arr, n, expected, "Insertion Sort Test 4: Already Sorted");
}

// ==============================================================
// MERGE SORT
//==============================================================

// ==============================================================
// Huy Phan
// Test the merge_sort method on regular case
//==============================================================
bool test_merge_sort_regular() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 5, 7, 8, 9, 10};

    merge_sort(arr, n);
    print_output(arr, n, "Merge Sort Test 1: Regular Case");
    return verify(arr, n, expected, "Merge Sort Test 1: Regular Case");
}

// ==============================================================
// Huy Phan
// Test the merge_sort method on duplicate case
//==============================================================
bool test_merge_sort_duplicates() {
    int arr[] = {4, 1, 3, 1, 2, 4};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 1, 2, 3, 4, 4};

    merge_sort(arr, n);
    print_output(arr, n, "Merge Sort Test 2: Duplicates");
    return verify(arr, n, expected, "Merge Sort Test 2: Duplicates");
}

// ==============================================================
// Huy Phan
// Test the merge_sort method on character case
//==============================================================
bool test_merge_sort_characters() {
    char arr[] = {'d', 'b', 'a', 'c', 'e'};
    long n = sizeof(arr) / sizeof(arr[0]);
    char expected[] = {'a', 'b', 'c', 'd', 'e'};

    merge_sort(arr, n);
    print_output(arr, n, "Merge Sort Test 3: Characters");
    return verify(arr, n, expected, "Merge Sort Test 3: Characters");
}

// ==============================================================
// Huy Phan
// Test the merge_sort method on already sorted case
//==============================================================
bool test_merge_sort_already_sorted() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 2, 3, 4, 5, 6};

    merge_sort(arr, n);
    print_output(arr, n, "Merge Sort Test 4: Already Sorted");
    return verify(arr, n, expected, "Merge Sort Test 4: Already Sorted");
}

// ==============================================================
// REGULAR QUICKSORT
//==============================================================

// ==============================================================
// Huy Phan
// Test the quicksort method on regular case
//==============================================================
bool test_quicksort_regular() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 5, 7, 8, 9, 10};

    quicksort(arr, n);
    print_output(arr, n, "Quicksort Test 1: Regular Case");
    return verify(arr, n, expected, "Quicksort Test 1: Regular Case");
}

// ==============================================================
// Huy Phan
// Test the quicksort method on duplicate case
//==============================================================
bool test_quicksort_duplicates() {
    int arr[] = {4, 1, 3, 1, 2, 4};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 1, 2, 3, 4, 4};

    quicksort(arr, n);
    print_output(arr, n, "Quicksort Test 2: Duplicates");
    return verify(arr, n, expected, "Quicksort Test 2: Duplicates");
}

// ==============================================================
// Huy Phan
// Test the quicksort method on character case
//==============================================================
bool test_quicksort_characters() {
    char arr[] = {'d', 'b', 'a', 'c', 'e'};
    long n = sizeof(arr) / sizeof(arr[0]);
    char expected[] = {'a', 'b', 'c', 'd', 'e'};

    quicksort(arr, n);
    print_output(arr, n, "Quicksort Test 3: Characters");
    return verify(arr, n, expected, "Quicksort Test 3: Characters");
}

// ==============================================================
// Huy Phan
// Test the quicksort method on already sorted case
//==============================================================
bool test_quicksort_already_sorted() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 2, 3, 4, 5, 6};

    quicksort(arr, n);
    print_output(arr, n, "Quicksort Test 4: Already Sorted");
    return verify(arr, n, expected, "Quicksort Test 4: Already Sorted");
}


// ==============================================================
// IMPROVED QUICKSORT
//==============================================================

// ==============================================================
// Huy Phan
// Test the improved_quicksort method on regular case
//==============================================================
bool test_improved_quicksort_regular() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 5, 7, 8, 9, 10};

    improved_quicksort(arr, n);
    print_output(arr, n, "Improved Quicksort Test 1: Regular Case");
    return verify(arr, n, expected, "Improved Quicksort Test 1: Regular Case");
}

// ==============================================================
// Huy Phan
// Test the improved_quicksort method on duplicate case
//==============================================================
bool test_improved_quicksort_duplicates() {
    int arr[] = {4, 1, 3, 1, 2, 4};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 1, 2, 3, 4, 4};

    improved_quicksort(arr, n);
    print_output(arr, n, "Improved Quicksort Test 2: Duplicates");
    return verify(arr, n, expected, "Improved Quicksort Test 2: Duplicates");
}

// ==============================================================
// Huy Phan
// Test the improved_quicksort method on character case
//==============================================================
bool test_improved_quicksort_characters() {
    char arr[] = {'d', 'b', 'a', 'c', 'e'};
    long n = sizeof(arr) / sizeof(arr[0]);
    char expected[] = {'a', 'b', 'c', 'd', 'e'};

    improved_quicksort(arr, n);
    print_output(arr, n, "Improved Quicksort Test 3: Characters");
    return verify(arr, n, expected, "Improved Quicksort Test 3: Characters");
}

// ==============================================================
// Huy Phan
// Test the improved_quicksort method on already sorted case
//==============================================================
bool test_improved_quicksort_already_sorted() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 2, 3, 4, 5, 6};

    improved_quicksort(arr, n);
    print_output(arr, n, "Improved Quicksort Test 4: Already Sorted");
    return verify(arr, n, expected, "Improved Quicksort Test 4: Already Sorted");
}


// ==============================================================
// RANDOMIZED QUICKSORT
//==============================================================

// ==============================================================
// Huy Phan
// Test the randomized_quicksort method on regular case
//==============================================================
bool test_randomized_quicksort_regular() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 5, 7, 8, 9, 10};

    randomized_quicksort(arr, n);
    print_output(arr, n, "Randomized Quicksort Test 1: Regular Case");
    return verify(arr, n, expected, "Randomized Quicksort Test 1: Regular Case");
}

// ==============================================================
// Huy Phan
// Test the randomized_quicksort method on duplicate case
//==============================================================
bool test_randomized_quicksort_duplicates() {
    int arr[] = {4, 1, 3, 1, 2, 4};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 1, 2, 3, 4, 4};

    randomized_quicksort(arr, n);
    print_output(arr, n, "Randomized Quicksort Test 2: Duplicates");
    return verify(arr, n, expected, "Randomized Quicksort Test 2: Duplicates");
}

// ==============================================================
// Huy Phan
// Test the randomized_quicksort method on character case
//==============================================================
bool test_randomized_quicksort_characters() {
    char arr[] = {'d', 'b', 'a', 'c', 'e'};
    long n = sizeof(arr) / sizeof(arr[0]);
    char expected[] = {'a', 'b', 'c', 'd', 'e'};

    randomized_quicksort(arr, n);
    print_output(arr, n, "Randomized Quicksort Test 3: Characters");
    return verify(arr, n, expected, "Randomized Quicksort Test 3: Characters");
}

// ==============================================================
// Huy Phan
// Test the randomized_quicksort method on already sorted case
//==============================================================
bool test_randomized_quicksort_already_sorted() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    long n = sizeof(arr) / sizeof(arr[0]);
    int expected[] = {1, 2, 3, 4, 5, 6};

    randomized_quicksort(arr, n);
    print_output(arr, n, "Randomized Quicksort Test 4: Already Sorted");
    return verify(arr, n, expected, "Randomized Quicksort Test 4: Already Sorted");
}

// ==============================================================
// Main Function
//==============================================================
int main() {
    int passed = 0, failed = 0;

    // INSERTION SORT TESTS
    cout<<"INSERTION SORT TESTS"<<endl;
    if (test_insertion_sort_regular()) passed++; else failed++;
    if (test_insertion_sort_duplicates()) passed++; else failed++;
    if (test_insertion_sort_characters()) passed++; else failed++;
    if (test_insertion_sort_already_sorted()) passed++; else failed++;
    cout<<endl<<endl;

    // MERGE SORT TESTS
    cout<<"MERGE SORT TESTS"<<endl;
    if (test_merge_sort_regular()) passed++; else failed++;
    if (test_merge_sort_duplicates()) passed++; else failed++;
    if (test_merge_sort_characters()) passed++; else failed++;
    if (test_merge_sort_already_sorted()) passed++; else failed++;
    cout<<endl<<endl;

    // QUICKSORT TESTS
    cout<<"QUICKSORT SORT TESTS"<<endl;
    if (test_quicksort_regular()) passed++; else failed++;
    if (test_quicksort_duplicates()) passed++; else failed++;
    if (test_quicksort_characters()) passed++; else failed++;
    if (test_quicksort_already_sorted()) passed++; else failed++;
    cout<<endl<<endl;
    // IMPROVED QUICKSORT TESTS
    cout<<"IMPROVED QUICK SORT TESTS"<<endl;
    if (test_improved_quicksort_regular()) passed++; else failed++;
    if (test_improved_quicksort_duplicates()) passed++; else failed++;
    if (test_improved_quicksort_characters()) passed++; else failed++;
    if (test_improved_quicksort_already_sorted()) passed++; else failed++;
    cout<<endl<<endl;
    // RANDOMIZED QUICKSORT TESTS
    cout<<"RANDOMIZED QUICK SORT TESTS"<<endl;
    if (test_randomized_quicksort_regular()) passed++; else failed++;
    if (test_randomized_quicksort_duplicates()) passed++; else failed++;
    if (test_randomized_quicksort_characters()) passed++; else failed++;
    if (test_randomized_quicksort_already_sorted()) passed++; else failed++;
    cout<<endl<<endl;
    // Output final test results
    cout << "Tests passed: " << passed << endl;
    cout << "Tests failed: " << failed << endl;

    return 0;
}

