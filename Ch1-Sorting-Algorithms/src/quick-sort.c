#include "quick-sort.h"


/*
 * File: quick-sort.c
 * Author: Michael Dunn
 * Creation Date: 16/02/2024
 *
 * This file contains the implementation of a simple quick sort algorithm (with recursion). 
 * 
 * This file takes a given array of doubles and conducts quick sort before printing the result.
 * 
 * Development & Iterations:
 * 1.   Next development would be to sort strings rather than doubles
 * 2.   Next development would be to take user input
 * 3.   Next development would be to read in data from a separate file, sort it, then output the data to a new file.
 * 
 * Brief overview of the functions provided by this module:
 *
 * - `main`:        Defines the array of numbers to be sorted; print the initial list; call quick_sort to sort the numbers; print the sorted list.
 * - `quick_sort`:  This function takes an array of doubles and sorts it using the quick sort algorithm
 *                  See description above the function for further details.
 * - `test_sort`:   This function tests if the array is sorted
 *
 */



//quick-sort algorithm

/// @brief - This function takes an array of pointers and sorts it using the quick sort algorithm
/// @param start - the start index of the array
/// @param end -  the end index of the array
/// @param arr - the array to be sorted
/// @param compare - the comparison function to be used to compare the elements of the array
/// @return - returns 0 to indicate success 
int quick_sort(int start,int end, void** arr, int (*compare)(void*, void*)){

    if (end <= start) {
        return 0;                                       //If the array has only one element, it is already sorted (or if you call quick-sort on an empty array)
    } else {

        // Partition the array
        int i = start - 1;
        int r = end; // r is the pivot

        for (int j = start; j < end; j++) {
            if (compare(arr[j], arr[r]) < 0) {                     // If the current element is less than or equal to the pivot
                i++;                                    // increment i
                void* swap_temp = arr[j];              // swap arr[i] and arr[j] using a temporary variable
                arr[j] = arr[i];
                arr[i] = swap_temp;
            }
        }

        //After looping through each element, swap the pivot arr[r] with arr[i+1] (large elements to the right, small elements to the left of the pivot)
        void* swap_temp = arr[r];
        arr[r] = arr[i+1];
        arr[i+1] = swap_temp;

        int new_start_1 = start;                        //assign new starting index for the array to the left of the pivot
        int new_end_1 = i;                              //assign new ending index for the array to the right of the pivot
        int new_start_2 = i+2;                         //assign new starting index of the array to the left of the pivot
        int new_end_2 = end;                           //assign new ending index of the array to the right of the pivot


        quick_sort(new_start_1, new_end_1, arr, compare);        //call quick_sort on the array to the left of the pivot
        quick_sort(new_start_2, new_end_2, arr, compare);        //call quick_sort on the array to the right of the pivot
                                        
        return 0;                                         //Return 0 to indicate success
    }
}

