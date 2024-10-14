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
#include <stdlib.h>
#include "DoublyLinkedList.hpp"

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

// Definition for quicksort
template<typename T>
    void quicksort(T* arr, long n) {
    
}

// Definition for improved quicksort
template<typename T>
    void improved_quicksort(T* arr, long n) {
    
}

// Definition for randomized quicksort
template<typename T>
    void randomized_quicksort(T* arr, long n);
