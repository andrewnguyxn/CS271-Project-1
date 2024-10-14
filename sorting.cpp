//==============================================================
// Names: Huy Phan, Tri Dang, Andrew Nguyen
// Class: CS 271-01
// Project 1:
// Date: 10/13/2024
// About: sorting.cpp contains the implementations of the 
// sorting algorithms, namely insertion_sort, merge_sort
// quicksort, randomized_quicksort and improved_quicksort.
//==============================================================
#include <iostream>
#include "sorting.hpp"
using namespace std;

//==============================================================
// Insertion_sort
// Author: Tri Dang
// Sorts the array in ascending order via comparison of each previous elements by incrementing indices. 
// Parameters:
//     Array, long n (length of array)
// Return value: 
//     None
//==============================================================
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
                    arr[j + 1] = arr[j]; //shift bigger elements to the right
                    j--;
                }
                arr[j + 1] = current;
            }
        }
}

// Definition for merge. Essential for merge_sort
template<typename T>
    void merge(T* arr ,T* firHalf, T* secHalf, long firN, long secN){
        long leftCount = 0; // splitted array of the 1st half
        long rightCount = 0; //splitted array of the 2nd half
        long arrCount = 0; // used for main array indices

        while((leftCount < firN) && rightCount < secN){ //comparison between 2 halves
            if(firHalf[leftCount] <= secHalf[rightCount]){
                arr[arrCount] = firHalf[leftCount];
                leftCount++;
            } else{
                arr[arrCount] = secHalf[rightCount];
                rightCount++;
            }
            arrCount++;
        }
        if (leftCount < firN){ //add remaining element from left half
            for (long j = leftCount; j < firN; j++){
                arr[arrCount] = firHalf[j];
                arrCount++;
            }
        }
        if (rightCount < secN){ //add remaining element from right half
            for (long i = rightCount; i < secN; i++){
                arr[arrCount] = secHalf[i];
                arrCount++;
            }
        }
    }

//==============================================================
// Merge_sort
// Author: Tri Dang
// We first split the array into its base case where it is an array of 1 element.
// Then, we compare each element, sort them to ascending order, building halves after halves.
// until we finally rebuilt the array into its sorted, ascended order. 
// Parameters:
//     Array, long n (length of array)
// Return value: 
//     None
//==============================================================
template<typename T>
    void merge_sort(T* arr, long n) {
        if (n <= 1){ //base case; cannot be split anymore.
            return;
        } else{
            long middle = n / 2;
            T* firHalf = new T[middle];
            T* secHalf = new T[n - middle];
            for (long i = 0; i < middle; i++){ //copies first half of an array
                firHalf[i] = arr[i];
            }
            for (long j = 0; j < n - middle; j++){ //copies other half of an array
                secHalf[j] = arr[j + middle];
            }
            merge_sort(firHalf, middle); // recursively halves array until it base case
            merge_sort(secHalf , n - middle);

            merge(arr, firHalf, secHalf, middle, n - middle);

            delete[] firHalf; //avoid memory leaks after merging
            delete[] secHalf;
        }
}

//==============================================================
// Function: exchange
// Huy Phan & Andrew Nguyen
// Description: 
// exchange two element within an array
// PARAMETERS:
// T& a, T& b: two elements a and b in an array
// RETURN VALUE:
// none, but swap a and b 
//==============================================================
template<typename T>
void exchange(T& a, T& b) {
    T temp = a;  
    a = b;       
    b = temp;    
}

//==============================================================
// Function : partition
// Andrew Nguyen
//
// Description: 
// Partitions the elements around the pivot, which is set to the
// last element of the array. Elements smaller than the pivot 
// will be moved to the left of the pivot, elements larger will  
// be moved to the right.
//
// PARAMETERS:
// T* arr       - Pointer to the array to be partitioned.
// long low     - The starting index of subarray.
// long high    - The ending index of subarray.
//
// RETURN VALUE:
// return the next pivot index
//==============================================================
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

//==============================================================
// Function : quicksort
// Andrew Nguyen
//
// Description: 
// Sort the array recurrsively using the quicksort algorithm by 
// chosing a pivot and partioning elements around it.
//
// PARAMETERS:
// T* arr       - Pointer to the array to be partitioned.
// long low     - The starting index of subarray.
// long high    - The ending index of subarray.
//
// RETURN VALUE: none
//==============================================================
template<typename T>
void quicksort(T *arr, long low, long high) {
    if (low < high) {
        long pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

//==============================================================
// Function : quicksort
// Andrew Nguyen
//
// Description: 
// Initial call of the quicksort fucntion
//
// PARAMETERS:
// T* arr       - Pointer to the array to be partitioned.
// long n       - Size of array
//
// RETURN VALUE: none
//==============================================================
template<typename T>
void quicksort(T *arr, long n) {
    quicksort(arr, 0, n - 1);
}

//==============================================================
// Function : randomized_partition
// Andrew Nguyen
//
// Description: 
// Choose a pivot point randomly between the lowest and highest index,
// swap it with the highest index then proceed as usual.
//
// PARAMETERS:
// T* arr       - Pointer to the array to be partitioned.
// long low     - The starting index of subarray.
// long high    - The ending index of subarray.
//
// RETURN VALUE: call the normal partition function with the modified array
//==============================================================
template<typename T>
long randomized_partition(T *arr, long low, long high) {
    // Generate a random index between low and high then proceed as usual
    long random_pivot = low + rand() % (high - low + 1);
    exchange(arr[random_pivot], arr[high]);
    return partition(arr, low, high);
}

//==============================================================
// Function : randomized_quicksort
// Andrew Nguyen
//
// Description: 
// Sort the array recurrsively using the quicksort algorithm by 
// chosing a pivot randomly and partioning elements around it.
//
// PARAMETERS:
// T* arr       - Pointer to the array to be partitioned.
// long low     - The starting index of subarray.
// long high    - The ending index of subarray.
//
// RETURN VALUE: none
//==============================================================
template<typename T>
void randomized_quicksort(T *arr, long low, long high) {
    if (low < high) {
        long pivot = randomized_partition(arr, low, high); 
        randomized_quicksort(arr, low, pivot - 1);
        randomized_quicksort(arr, pivot + 1, high); 
    }
}

//==============================================================
// Function : randomized_quicksort
// Andrew Nguyen
//
// Description: 
// Initial call of the randomized_quicksort function
//
// PARAMETERS:
// T* arr       - Pointer to the array to be partitioned.
// long n       - Size of array
//
// RETURN VALUE: none
//==============================================================
template<typename T>
void randomized_quicksort(T *arr, long n) {
    randomized_quicksort(arr, 0, n - 1);
}

//==============================================================
// Function : find_median_pivot_index
// Huy Phan
// Description: 
// Find median in the sub array
// PARAMETERS:
// Array, low, and high which are the smallest and highest index
// inside of a sub array
// RETURN VALUE:
// return the median pivot index
//==============================================================
template <typename T>
T find_median_pivot_index(T *arr, long low, long high){
    if(high - low + 1 < 3){
        return high; 
    }
    long mid = (low + high) / 2; 
    T first_item = arr[low], median_item = arr[mid], last_item = arr[high];

    // Determing the median between 3 values
    if ((first_item <= median_item && median_item <= last_item) || (last_item <= median_item && median_item <= first_item)) {
        return mid;
    } else if ((median_item <= first_item && first_item <= last_item) || (last_item <= first_item && first_item <= median_item)) {
        return low;
    } else {
        return high;
    }
}

//==============================================================
// Function: median partition
// Author: Huy Phan
// Description: 
// Partitions the array around a pivot element, using the median-of-three strategy 
// to select the pivot. The pivot is placed in its correct sorted position, and all 
// elements less than the pivot are moved to the left, while all greater elements 
// are moved to the right.
//
// PARAMETERS:
// T* arr       - Pointer to the array to be partitioned.
// long low     - The starting index of subarray.
// long high    - The ending index of subarray.
//
// RETURN VALUE:
// long         - The index of the pivot element after partitioning.
//==============================================================
template<typename T>
long median_partition(T *arr, long low, long high) {
    long medianIndex = find_median_pivot_index(arr,low,high);
    exchange(arr[medianIndex], arr[high]);

    T pivot = arr[high];
    long i = (low - 1);

    for (long j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            exchange(arr[i], arr[j]);
        }
    }
    // Swap the pivot element with the element at index (i + 1)
    exchange(arr[i + 1], arr[high]); 
    return (i + 1); // Return the pivot index
}

//==============================================================
// Function: fixed_improved_quicksort
// Huy Phan
// Description: 
// Mainly use for convenience 
// Recursively sorts an array segment using the quicksort algorithm, selecting a pivot
// element and partitioning the segment around it. 
//
// PARAMETERS:
// T* arr       - Pointer to the array to be sorted.
// long low     - The starting index of the sub array
// long high    - The ending index of the subarray
//
// RETURN VALUE:
// None         - The array is sorted in-place.
//
//==============================================================
template<typename T>
void fixed_improved_quicksort(T *arr, long low, long high) {
    if (low < high) {
        long pivot = median_partition(arr, low, high);
        fixed_improved_quicksort(arr, low, pivot - 1); //Left subarray
        fixed_improved_quicksort(arr, pivot + 1, high); //Right subarray
    }
}

//==============================================================
// Function: improved_quicksort
// Huy Phan
// Description: 
// Used to call fixed_improved_quicksort for convenience
//
// PARAMETERS:
// T* arr       - Pointer to the array to be sorted.
// long low     - The starting index of the sub array
// long high    - The ending index of the subarray
//
// RETURN VALUE:
// None         - The array is sorted in-place.
//
//==============================================================
template<typename T>
void improved_quicksort(T *arr, long n) {
    fixed_improved_quicksort(arr, 0, n-1);
}
