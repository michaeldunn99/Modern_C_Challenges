#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test-functions.h" 
#include "merge-sort.h"
#include "quick-sort.h"


/*
 * File: main.c
 * Author: Michael Dunn
 * Creation Date: 15/02/2024
 *
 * This file defines two arrays: one array of real numbers and one array of strings.
 * The file then calls the merge_sort and quick-sort functions, respectively to sort the arrays, then print the sorted arrays.
 * 
 * This main.c file is compiled with the merge-sort.c, quick-sort.c and test-functions.c files to create an executable.
 * 
 * Related files:
 *  - merge-sort.c: contains the implementation of the merge sort algorithm.
 *  - quick-sort.c: contains the implementation of the quick sort algorithm.
 *  - test-functions.c: contains the implementation of the test functions used to check if the arrays are sorted.
 * 
 * Development & Iterations:
 * 1.   Next development would be to take user input
 * 2.   Next development would be to read in data from a separate file, sort it, then output the data to a new file.
 * 
 * Brief overview of the functions provided by this module:
 *
 * - `main`: Main is organised in three sections: DEFINITION, MERGE-SORT and QUICK-SORT
 *          - The DEFINITION section defines the arrays to be sorted (by quick-sort and merge-sorted) as well as the length of the arrays.
 *          - The MERGE-SORT section applies merge-sort to the arrays of doubles and strings, and prints the sorted arrays.
 *          - The QUICK-SORT section applies quick-sort to the arrays of doubles and strings, and prints the sorted arrays.
 *  
 */

//Main function

int main(void) {    

/*
*
* DEFINITION SECTION:   IN THIS SECTION WE WILL DEFINE THE ARRAYS TO BE SORTED (BY QUICK-SORT AND MERGE-SORTED)
*                       AS WELL AS THE LENGTH OF THE ARRAYS
*
*/

    // Define the array of numbers to be sorted (via both merge and quick sort algorithms)
    double static_array[] = {2.34, 1.79, 5.30, 96.5,    
                            1.03, 3.14, 1.22, 0.01, 
                            99.87, 4.34};
    
    // Define the length of the array of doubles
    int double_length = 10;                                    

    // Define the array of names to be sorted (by both merge and quick sort algorithms)
    char* static_string_array[] =  {"Luke Skywalker",
                                    "Princess Leia",
                                    "Han Solo",
                                    "Darth Vader",
                                    "General Kenobi!",
                                    "Yoda",
                                    "Chewbacca",
                                    "R2-D2",
                                    "C-3PO",
                                    "Emperor Palpatine"}; 

    
    int string_length = 10;                                                     // Define the length of the array of strings       


    
/*
*
* MERGE-SORT SECTION: IN THIS SECTION WE WILL SORT BOTH THE ARRAYS ABOVE USING THE MERGE SORT ALGORITHM
*
*/

    printf("\n MERGE SORT SECTION\n\n");

    /*
    * APPLY MERGE-SORT TO THE ARRAY OF DOUBLES
    */
    void**double_array = malloc(sizeof(void*) * double_length);                // Allocate memory for the dynamic array
    
    for (int i = 0; i < double_length; i++) {                                       // Copy the static array into the dynamic array
        double_array[i] = malloc(sizeof(double));
        *(double*)double_array[i] = static_array[i];
    }


    printf("Double Array initially:\n[");                                           // Print the initial array with exception of last entry
    for (int i = 0; i < double_length-1; i++) {
        printf("%.2f, ", *(double*)double_array[i]);
    }

    printf("%.2f\n", *(double*)double_array[double_length-1]);                      // Print the last entry and a newline at the end

    
    merge_sort(0, double_length-1, double_array, compare_doubles);       // Call the merge_sort function to sort the array

    if (!test_sort(double_length, double_array)) {                                  // Call test_sort function to check if array is sorted
        printf("Array not sorted correctly\n");
        return 1;
    }

    printf("\nMerge Sorted Double Array:\n[");
    for (int i = 0; i < double_length-1; i++) {                                     // Print the sorted array with exception of last entry
        printf("%.2f, ", *(double*)double_array[i]);
    }
    printf("%.2f]\n\n", *(double*)double_array[double_length-1]);
                                

    /*
    * APPLY MERGE-SORT TO THE ARRAY OF STRINGS
    */
                                        
    void** str_array = malloc(sizeof(void*) * string_length);                  // Allocate memory for the dynamic array of pointers to char*'s
    if (str_array == NULL) {                                                        //Check if memory allocation was successful
        printf("Memory allocation failed");
        return 1;
    }
                     
    int max_length = 0;                                                             // Calculate the length of the longest word
    for (int i = 0; i < string_length; i++) {                      
        int j = 0;
        do {
            j++;
        } while (static_string_array[i][j] != '\0');
        if (j > max_length) {
            max_length = j;
        }
    }

    printf("String Array initially:\n");
    for (int i = 0; i < string_length; i++) {
        str_array[i] = malloc(sizeof(char) * max_length+1);                    //Assign dynamic memory for each string
        if (str_array[i] == NULL) {
            printf("Memory allocation failed");                                     //Check if memory allocation was successful
            return 1;
        }
        strcpy((char*)str_array[i], static_string_array[i]);                        //Copy string from static array to dynamic array                
        printf("%s\n", (char*)str_array[i]);                                        // Print the array
    }
    
    merge_sort(0 , string_length - 1, str_array, compare_strings);                  // Call the merge_sort function to sort the array
    
                    
    if (!test_sort_string(string_length, str_array)) {                     // Call the test function to ensure array is sorted - exit the program if not
        printf("Array not sorted correctly\n");
        return 1;
    }


    printf("\nMerge Sorted String Array:\n");
    for (int i = 0; i < string_length-1; i++) {                 // Print the sorted array with exception of last entry
        printf("%s\n", (char*)str_array[i]);
    }
    printf("%s\n", (char*)str_array[string_length-1]);          // Print the last entry and a newline at the end
    

    
    
/*
*
* QUICK-SORT SECTION: IN THIS SECTION WE WILL SORT BOTH THE ARRAYS ABOVE USING THE QUICK SORT ALGORITHM
*
*/                                        

    /*
    * APPLY QUICK-SORT TO THE ARRAY OF DOUBLES
    */

    /*
    *   Re-assign the values of the static array to the dynamic array 
    *   (i.e. undo the changes made by merge_sort, putting array back into unsorted order)                 
    */

   printf("\nQUICK SORT SECTION\n\n");

    
    for (int i = 0; i < double_length; i++) {
        *(double*)double_array[i] = static_array[i];  
    }

    printf("Double Array initially:\n");                                             // Print the initial array with exception of last entry
    for (int i = 0; i < double_length-1; i++) {
        printf("%.2f, ", *(double*)double_array[i]);
    }

    printf("%.2f]\n\n", *(double*)double_array[double_length-1]);                   // Print the last entry and a newline at the end

    
    quick_sort(0 , double_length - 1, double_array, compare_doubles);                  // Call the quick_sort function to sort the array

    if (!test_sort(double_length, double_array)) {                                  // Call test_sort function to check if array is sorted
        printf("Array not sorted correctly\n");
        return 1;
    }

    printf("Quick Sorted Double Array:\n[");
    for (int i = 0; i < double_length-1; i++) {                                     // Print the sorted array with exception of last entry
        printf("%.2f, ", *(double*) double_array[i]);
        free(double_array[i]);                                                      //Free memory allocated for each entry
    }
    printf("%.2f]\n\n", *(double*)double_array[double_length-1]);                   // Print the last entry and a newline at the end
    free(double_array[double_length-1]);                                            // Free the memory allocated for the last entry
    free(double_array);                                                             // Free the memory allocated for the dynamic array 
    
    



    /*
    * APPLY QUICK-SORT TO THE ARRAY OF STRINGS
    */
   
    /*
    * Re-assign the values of the static array of strings to the dynamic array of strings
    * (Undoing the changes made by merge_sort, putting array back into unsorted order)
    */
    printf("String Array initially:\n");  
    for (int i = 0; i < string_length; i++) {
        strcpy(str_array[i], static_string_array[i]);                                      
        printf("%s\n", (char*) str_array[i]);                                                   // Print the array
    }

    quick_sort(0 , string_length - 1, str_array, compare_strings);                  // Call the quick_sort function to sort the array

    if (!test_sort_string(string_length, str_array)) {                                         // Call test_sort function to check if array is sorted
        printf("Array not sorted correctly\n");
        return 1;
    }
    
    printf("\nQuick Sorted String Array:\n");
    for (int i = 0; i < string_length-1; i++) {                                     // Print the sorted array with exception of last entry
        printf("%s\n", (char*)str_array[i]);
        free(str_array[i]);                                                         //Free memory allocated for each entry
    }
    printf("%s\n", (char*) str_array[string_length-1]);                             // Print the last entry and a newline at the end
    free(str_array[string_length-1]);                                               // Free the memory allocated for the last entry
    free(str_array);                                                                // Free the memory allocated for the array
    return 0; 
}


