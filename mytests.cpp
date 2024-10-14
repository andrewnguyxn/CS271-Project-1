#include <iostream>
#include "sorting.hpp"  // Include the sorting header file

using namespace std;

// Function to print the array for debugging
template<typename T>
void printArray(T arr[], long n) {
    for (long i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main test function
int main() {
    // Test case 1: Integer array
    int arr1[] = {10, 7, 8, 9, 1, 5};
    long n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Original integer array: ";
    printArray(arr1, n1);
    
    quicksort(arr1, n1);  // Calling the template quicksort function
    cout << "Sorted integer array: ";
    printArray(arr1, n1);

    int arr2[] = {10,20,0, 7, 8, 9, 1, 5,2,45,6,78};
    long n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Original integer array: ";
    printArray(arr2, n2);
    
    randomized_quicksort(arr2, n2);  // Calling the template quicksort function
    cout << "Sorted integer array: ";
    printArray(arr2, n2);
}