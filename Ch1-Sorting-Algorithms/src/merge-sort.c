#include "merge-sort.h"


/*
 * File: merge-sort.c
 * Author: Michael Dunn
 * Creation Date: 14/02/2024
 *
 * This file contains the implementation of a simple merge sort algorithm (with recursion). 
 * 
 * This file takes a given array of doubles and conducts merge sort before printing the result.
 * 
 * Development & Iterations:
 * 1.   Next development would be to sort strings rather than doubles
 * 2.   Next development would be to take user input
 * 3.   Next development would be to read in data from a separate file, sort it, then output the data to a new file.
 * 
 * Brief overview of the functions provided by this module:
 *
 * - `main`:        Defines the array of numbers to be sorted; print the initial list; call merge_sort to sort the numbers; print the sorted list.
 * - `merge_sort`:  This function takes an array of doubles and sorts it using the merge sort algorithm
 *                  See description above the function for further details.
 * - `test_sort`:   This function tests if the array is sorted
 *
 */





//merge-sort algorithm

/// @brief - This function takes an array of doubles and sorts it using the merge sort algorithm
/// @param start - the start index of the array
/// @param end -  the end index of the array
/// @param arr - the array to be sorted
/// @param compare - the comparison function to be used to compare the elements of the array
/// @return - returns 0 to indicate success 
int merge_sort(int start, int end,  void** arr, int (*compare)(void*, void*)) {

    if (end == start) {
        return 0;                                       //If the array has only one element, it is already sorted
    } else {

        int new_start_1 = start;                        //starting index of the first half of the array
        int new_end_1 = start + (end-start)/2;          //ending index of the first half of the array

        int new_start_2 = start + (end-start)/2 + 1;    //starting index of the second half of the array
        int new_end_2 = end;                            //ending index of the second half of the array

        merge_sort(new_start_1, new_end_1, arr, compare);        //call merge_sort on the first half of the array

        merge_sort(new_start_2, new_end_2, arr, compare);        //call merge_sort on the second half of the array
        
        void **merged_temp = malloc(sizeof(void*)*(end - start + 1)); //temporary array to store the merged array

        int m = 0;
        int n = 0;

                                                        
    for (;;) {                                          //Merge the two halves of the array into merged_temp
            if (m == (new_end_1 - new_start_1 + 1)) {   //If the first half of the array has been completely merged
                while (n < (new_end_2 - new_start_2 + 1)) {
                    merged_temp[m+n] = arr[new_start_2 + n]; //Copy the remaining elements of the second half of the array into merged_temp
                    n++;
                }
                break;                                  //Exit the loop
            } else if (n == (new_end_2 - new_start_2 + 1)) {
                while (m < (new_end_1 - new_start_1 + 1)) { //If the second half of the array has been completely merged
                    merged_temp[m+n] = arr[new_start_1 + m]; //Copy the remaining elements of the first half of the array into merged_temp
                    m++;
                }
                break;                                  //Exit the loop
            } else if (compare(arr[new_start_1 + m], arr[new_start_2 + n]) <= 0) { //If current element of 1st half of array <= current element of 2nd half
                merged_temp[m+n] = arr[new_start_1 + m]; //Copy the current element of the first half into merged_temp
                m++;
            } else {
                merged_temp[m+n] = arr[new_start_2 + n]; //Else copy current element of the second half into merged_temp
                n++;
            }
        }

        for (int i = 0; i < end - start + 1; i++) {         //Copy the merged_temp array back into the original array
            arr[start+i] = merged_temp[i];
        }

        free(merged_temp);                                 //Free the memory allocated for the temporary array
        return 0;                                          //Return 0 to indicate success
    }
}

