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
using namespace std;

// Definition for insertion sort
template<typename T>
    void insertion_sort(T* arr, long n) {
}
// Definition for merge sort
template<typename T>
    void merge_sort(T* arr, long n) {
    
}

// Definition for quicksort
template<typename T>
    void quicksort(T* arr, long n) {
    
}

// Definition for randomized quicksort
template<typename T>
    void randomized_quicksort(T* arr, long n);

template <typename T>
    T find_median_pivot_index(T *arr, long low, long high)
    {
        if(high - low + 1 < 3){
            return high; 
        }
        long mid = (low + high) / 2; 
        T first = arr[low], middle = arr[mid], last = arr[high];

        if ((first <= middle && middle <= last) || (last <= middle && middle <= first)) {
            return mid;
        } else if ((middle <= first && first <= last) || (last <= first && first <= middle)) {
            return low;
        } else {
            return high;
        }
    }

template<typename T>
    void swapping(T& a, T& b) {
        T temp = a;  
        a = b;       
        b = temp;    
}

template<typename T>
long partition(T* arr, long low, long high) {
    long medianIndex = find_median_pivot_index(arr,low,high);
    swapping(arr[medianIndex], arr[high]);

    T pivot = arr[high];
    long i = (low - 1);

    for (long j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swapping(arr[i], arr[j]);
        }
    }
    swapping(arr[i + 1], arr[high]);
    return (i + 1);
}

template<typename T>
void fixed_improved_quicksort(T* arr, long low, long high) {
    if (low < high) {
        long pivot = partition(arr, low, high);
        fixed_improved_quicksort(arr, low, pivot - 1);
        fixed_improved_quicksort(arr, pivot + 1, high);
    }
}
// Definition for improved quicksort
template<typename T>
    void improved_quicksort(T* arr, long n) {
        fixed_improved_quicksort(arr, 0, n-1);
}


