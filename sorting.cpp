#include "sorting.hpp" 


template<typename T>
void exchange(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

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

template<typename T>
void quicksort(T *arr, long low, long high) {
    if (low < high) {
        long pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

template<typename T>
void quicksort(T *arr, long n) {
    quicksort(arr, 0, n - 1);
}

template<typename T>
long randomized_partition(T *arr, long low, long high) {
    // Generate a random index between low and high
    long random_pivot = low + rand() % (high - low + 1);

    // Swap the randomly chosen pivot with the last element (standard pivot position)
    exchange(arr[random_pivot], arr[high]);

    // Proceed with partitioning as usual
    return partition(arr, low, high);
}

// Recursive randomized quicksort function
template<typename T>
void randomized_quicksort(T *arr, long low, long high) {
    if (low < high) {
        long pivot = randomized_partition(arr, low, high);  // Randomized partitioning
        randomized_quicksort(arr, low, pivot - 1);  // Recursively sort left subarray
        randomized_quicksort(arr, pivot + 1, high);  // Recursively sort right subarray
    }
}

template<typename T>
void randomized_quicksort(T *arr, long n) {
    randomized_quicksort(arr, 0, n - 1);  // Initial call with full array
}

