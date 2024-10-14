#include <iostream>
#include <fstream>
#include <cstdlib>
#include "sorting.cpp"
#include <algorithm>
#include <chrono>
#include <iomanip> // For setting precision

using namespace std;

void deepCopy(int* source, int* destination, int size) {
    for (int i = 0; i < size; ++i) {
        destination[i] = source[i];
    }
}

void plot(int SIZE, ofstream& csv_file) {
    int insert[SIZE];
    int merge[SIZE];
    int qs[SIZE];
    int iqs[SIZE];
    int rqs[SIZE];
    int ds[SIZE];

    // Fill the array with random numbers
    for (int i = 0; i < SIZE; i++) {
        insert[i] = rand() % SIZE; 
    }

    deepCopy(insert, merge, SIZE);
    deepCopy(insert, qs, SIZE);
    deepCopy(insert, iqs, SIZE);
    deepCopy(insert, rqs, SIZE);
    deepCopy(insert, ds, SIZE);

    csv_file << SIZE;

    // Measure runtime for insertion sort
    auto start = std::chrono::high_resolution_clock::now();
    insertion_sort<int>(insert, SIZE);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
    csv_file << "," << duration;

    // Measure runtime for merge sort
    start = std::chrono::high_resolution_clock::now();
    merge_sort<int>(merge, SIZE);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
    csv_file << "," << duration;

    // Measure runtime for quicksort
    start = std::chrono::high_resolution_clock::now();
    quicksort<int>(qs, SIZE);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
    csv_file << "," << duration;

    // Measure runtime for improved quicksort
    start = std::chrono::high_resolution_clock::now();
    improved_quicksort<int>(iqs, SIZE);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
    csv_file << "," << duration;

    // Measure runtime for randomized quicksort
    start = std::chrono::high_resolution_clock::now();
    randomized_quicksort<int>(rqs, SIZE);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
    csv_file << "," << duration;

    // Measure runtime for default sort
    start = std::chrono::high_resolution_clock::now();
    sort(ds, ds + SIZE);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
    csv_file << "," << duration;

    csv_file << "\n";
}

int main() {
    ofstream csv_file("runtime_data_output.csv");

    // Set precision for floating-point output to 5 decimal places
    csv_file << std::fixed << std::setprecision(7);

    csv_file << "InputSize,InsertionSort,MergeSort,Quicksort,ImprovedQuicksort,RandomizedQuicksort,DefaultSort\n";

    int SIZE = 10;
    while (SIZE <= 100000) {
        plot(SIZE, csv_file);
        SIZE *= 10;
    }

    csv_file.close();
    cout << "Runtime data has been written to runtime_data_output.csv" << endl;

    return 0;
}
