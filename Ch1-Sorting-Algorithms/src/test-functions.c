#include "test-functions.h"



/// @brief This function tests if the array is sorted
/// @param length length of the array
/// @param arr pointer to the array
/// @return true if array is sorted, false otherwise

bool test_sort_string(int length, void** arr) {
    for (int i = 0; i < length - 1; i++) {
        if (strcmp((char*)arr[i],(char*) arr[i+1]) > 0) {
            return false;
        }
    }
    return true;
}



/// @brief This function tests if an array of doubles is sorted
/// @param length length of the array
/// @param arr pointer to the array
/// @return true if array is sorted, false otherwise

bool test_sort(int length, void** arr) {
    for (int i = 0; i < length - 1; i++) {
        if (*(double*)arr[i] > *(double*)arr[i+1]) {
            return false;
        }
    }
    return true;
}

int compare_strings(void* a, void* b) {
    return strcmp((char*)a, (char*)b);
}

int compare_doubles(void* a, void* b) {
    double diff = *(double*)a - *(double*)b;
    return (diff > 0) - (diff < 0);
}