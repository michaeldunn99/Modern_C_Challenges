#ifndef HELPER_FUNCTIONS
#define HELPER_FUNCTIONS

#include <stdlib.h>
#include <stdint.h>

// Declare the init_parent function which initializes the index table
size_t** init_parent(size_t set_size);

//Declare the Find function
size_t find(size_t index, size_t** index_table);

//Declare the FindReplace function
void find_replace(size_t find_element, size_t replace_element, size_t ** index_array);

//Declare the FindCompress function
void find_compress(size_t find_element, size_t ** index_array);

//Declare the FindUnion function
void find_union(size_t first_element, size_t second_element, size_t **index_array);

#endif