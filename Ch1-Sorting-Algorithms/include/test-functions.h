#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include <stdbool.h>
#include <string.h>

/*
* Declare the function test_sort_string for sorting strings
*/
bool test_sort_string(int length, void** arr);

/*
* Declare the function test_sort for sorting reals
*/
bool test_sort(int length, void** arr);

// Declare the compare_strings function
int compare_strings(void* a, void* b);

//Declare the compare_doubles function
int compare_doubles(void* a, void* b);
#endif // TEST_FUNCTIONS_H

