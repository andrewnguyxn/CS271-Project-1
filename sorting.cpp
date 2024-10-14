//==============================================================
// Names: Huy Phan, Tri Dang, Andrew Nguyen
// Class: CS 271-01
// Project 1:
// Date: 10/13/2024
// About: DoublyLinkedList.cpp contains the implementations of
// the methods for the DoublyLinkedList class, as defined in
// the header file DoublyLinkedList.hpp.
//==============================================================
#include <iostream>
#include "sorting.hpp"

// Definition for insertion sort
template<typename T>
    void insertion_sort(T* arr, long n) {
        // length n = 1 is "sorted"
        if (n > 1){
            int j;
            T current;
            for (long i = 1; i < n; i++ ){
                j = i - 1;
                current = arr[i];
                while (j >= 0 && arr[j] > current){ //condition 1: iterates backward from array until last element, condition 2: element before is greater than current element
                    arr[j] = arr[j + 1];
                    j--;
                }
                arr[j + 1] = current;
            }
        }
}

// Definition for merge sort
template<typename T>
    void merge_sort(T* arr, long n) {
    
}

// Swap function
template<typename T>
void exchange(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Partition function
template<typename T>
long partition(T *arr, long low, long high) {
    T pivot = arr[high];
    long i = low - 1;

    for (long j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            exchange(arr[i], arr[j]);
        }
    }
    exchange(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quicksort function
template<typename T>
void quicksort(T *arr, long low, long high) {
    if (low < high) {
        long pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

// Initial call of quicksort function
template<typename T>
void quicksort(T *arr, long n) {
    quicksort(arr, 0, n - 1);
}

// Randomized partion function
template<typename T>
long randomized_partition(T *arr, long low, long high) {
    // Generate a random index between low and high then proceed as usual
    long random_pivot = low + rand() % (high - low + 1);
    exchange(arr[random_pivot], arr[high]);
    return partition(arr, low, high);
}

// Recursive randomized quicksort function
template<typename T>
void randomized_quicksort(T *arr, long low, long high) {
    if (low < high) {
        long pivot = randomized_partition(arr, low, high); 
        randomized_quicksort(arr, low, pivot - 1);
        randomized_quicksort(arr, pivot + 1, high); 
    }
}

// Initial call of randomized quicksort function
template<typename T>
void randomized_quicksort(T *arr, long n) {
    randomized_quicksort(arr, 0, n - 1);
}

// Definition for improved quicksort
template<typename T>
    void improved_quicksort(T* arr, long n);
