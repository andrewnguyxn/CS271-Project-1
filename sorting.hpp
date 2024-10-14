#include <iostream>
#include <string>
using namespace std;

#ifndef SORTING_HPP
#define SORTING_HPP

template <class T>
void quicksort(T *arr, long n);

template <class T>
void randomized_quicksort(T *arr, long n);

#include "sorting.cpp"

#endif