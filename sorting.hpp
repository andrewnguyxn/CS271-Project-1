//==============================================================
// Names: Huy Phan, Andrew Nguyen, Tri Dang
// Class: CS 271
// Project 1
// Date: 10/13/2024
// About: sorting.hpp contains the declarations of
// the functions including the insertionSort, mergesort, quicksort,
// improved quicksort, and randomized quicksort
//==============================================================
#include <iostream>
using namespace std;

#ifndef SORTING_HPP
#define SORTING_HPP

// Declaration for insertion sort
template<typename T>
    void insertion_sort(T* arr, long n);

// Declaration for merge sort
template<typename T>
    void merge_sort(T* arr, long n);

// Declaration for quicksort
template<typename T>
    void quicksort(T* arr, long n);

// Declaration for improved quicksort
template<typename T>
    void improved_quicksort(T* arr, long n);

template<typename T>
    void randomized_quicksort(T* arr)
#endif

