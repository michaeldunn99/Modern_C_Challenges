#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "helper-functions.h"

//Forward declaration 

//Define structure for index table
/*typedef struct table_element {
    size_t index;
    struct table_element* parent;
} table_element;

*/

//Declare the free index function which frees the dynamic memory allocated for the index table
void free_index(size_t index_size, size_t **index_table);

//Declare the print trees function which prints the trees in the index table to the terminal
void print_trees(size_t array_size, size_t ** index_array);





/**
 * @file main.c
 * @brief This file contains the main function for the Union-Find algorithm.
 *
 * The main function initializes the Union-Find data structure, performs various operations on it,
 * and prints the resulting trees. It takes the size of the ground set as a command line argument.
 * If the first command line argument is not a positive integer, the size of the ground set is set to SIZE_MAX.
 *
 * @param argc The number of command line arguments.
 * @param argv An array of strings containing the command line arguments.
 * @return 0 on successful execution.
 */
int main(int argc, char* argv[]) {

    //First command line argument is size of the ground set
    size_t set_size = atoi(argv[1]);
    //Add functionality that sets set_size = SIZE_MAX if the first command line argument is not a positive integer

    //Call the initialization function with the size of the ground set and print the result
    size_t **index_array = init_parent(set_size);
    print_trees(set_size, index_array);

    //Replace the every parent in the tree below the 4th element with the 5th element (including the root) and print the result
    find_replace(4,5,index_array);
    print_trees(set_size, index_array);

    //Replace the every parent in the tree below the 3rd element with the 4th element (including the root) and print the result
    find_replace(3,4,index_array);
    print_trees(set_size, index_array);

    //Set the parent of the 2nd element to the 3rd element
    index_array[2][0] = 3;

    //Set the parent of the 0th element to the third element and print the result
    index_array[0][0] = 3;
    print_trees(set_size, index_array);

    //Set the parent of the 5th element to the 6th element and print the result
    index_array[5][0] = 6;
    print_trees(set_size, index_array);

    //Compress every node in the tree below the 0th element to point to the root and print the result
    find_compress(0, index_array);
    print_trees(set_size, index_array);

    //Set the parent of the 3rd element to the 1st element and print the result
    index_array[3][0] =1;
    print_trees(set_size, index_array);

    //Combine the sets containing the trees of the 0th and 1st elements respectively and print the result
    find_union(0, 1, index_array);
    print_trees(set_size, index_array);

    //Free the memory allocated for the index table by calling the free_index function
    free_index(set_size, index_array);
    return 0;
}



/**
 * Frees the memory allocated for the index table.
 * 
 * @param index_size The size of the index table.
 * @param index_table The index table to be freed.
 */
void free_index(size_t index_size, size_t **index_table) {
    for (int i = 0; i < index_size; i++) {
        free(index_table[i]);
    }
    free(index_table);
}

/**
 * Prints the trees represented by the index_array.
 * 
 * @param array_size The size of the index_array.
 * @param index_array The array containing the indices and parent indices.
 */
void print_trees(size_t array_size, size_t ** index_array) {
    // Create a 2D array to store the index, parent, and root of each element
    size_t index_parent_root[array_size][3];
    size_t trees = 0;
    
    // Populate the index_parent_root array and count the number of trees
    for(int i = 0; i < array_size; i++) {
        index_parent_root[i][0] = i;
        index_parent_root[i][1] = index_array[i][0];
        index_parent_root[i][2] = find(index_array[i][0], index_array);
        
        // If the element is its own parent, it is a root of a tree
        if (i == index_array[i][0]) {
            trees++;
        }        
    }
    
    // Create an array to store the roots of the trees
    size_t roots[trees];
    size_t j = 0;
    
    // Populate the roots array with the indices of the roots
    for (int i = 0; i < array_size; i++) {
        if (i == index_array[i][0]) {
            roots[j] = i;
            j++;
        }
    }
    
    // Print the trees
    for (int i = 0; i < trees; i++) {
        for (int j = 0; j < array_size; j++) {
            // If the element's root matches the current root, print its details
            if (find(j, index_array) == roots[i]) {
                printf("Root:%zu\tIndex:%zu\tParent:%zu\n", index_parent_root[j][2],index_parent_root[j][0],index_parent_root[j][1]);
            }
        }
        printf("\n");
    }
    printf("\n\n");
}




