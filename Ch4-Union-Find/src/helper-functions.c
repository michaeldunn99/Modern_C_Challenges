#include "helper-functions.h"

/**
 * Initializes the parent index array for the Union-Find data structure.
 * 
 * @param set_size The size of the index array.
 * @return The initialized parent index array.
 */
size_t** init_parent(size_t set_size) {

    size_t** index_array = malloc(sizeof(size_t*) * set_size);

    for (int i = 0; i < set_size; i++) {
        index_array[i] = malloc(sizeof(size_t));
        index_array[i][0] = i;
    }
    return index_array;
}

/**
 * Finds the root index of the given index in the Union-Find data structure.
 * 
 * @param index The index to find the root for.
 * @param index_table The parent index array.
 * @return The root index of the given index.
 */
size_t find(size_t index, size_t** index_table) {
    size_t search_index = index;
    while (index_table[search_index][0] != search_index) {
        search_index = index_table[search_index][0];
    }
    return search_index;
}


/**
 * @brief Finds and replaces an element in the index array.
 * 
 * This function searches for the specified element in the index array and replaces its parent and the parent of each of the nodes in its tree with the specified replacement element.
 * It uses the union-find algorithm to find the parent of the element and updates the parent of every node in its tree to the replacement element (including the root node).
 * 
 * @param find_element The element to be found and whose tree is to be replaced.
 * @param replace_element The element to replace the parents of the elements in the found element's tree with.
 * @param index_array The index array containing the elements.
 */
void find_replace(size_t find_element, size_t replace_element, size_t ** index_array) {
    size_t element = find_element;
    size_t temp_parent;
    while (index_array[element][0] != element) {
        temp_parent = index_array[element][0];
        index_array[element][0] = replace_element;
        element = temp_parent;
    }
    index_array[element][0] = replace_element;
}

/**
 * @brief Compresses the path to the root element of a given element in the index array.
 *
 * This function compresses the path to the root element of a given element in the index array
 * by updating the parent of each element along the path to the root element to the root element itself.
 *
 * @param find_element The element for which the path needs to be compressed.
 * @param index_array The index array containing the elements and their parents.
 */
void find_compress(size_t find_element, size_t ** index_array) {
    size_t element = find_element;
    size_t temp_parent;
    size_t replace_element = find(find_element, index_array);
    while (index_array[element][0] != element) {
        temp_parent = index_array[element][0];
        index_array[element][0] = replace_element;
        element = temp_parent;
    }
}

/**
 * Performs the find-union operation on two elements in the index array.
 * 
 * @param first_element The index of the first element.
 * @param second_element The index of the second element.
 * @param index_array The index array containing the elements.
 */
void find_union(size_t first_element, size_t second_element, size_t **index_array) {
    find_compress(second_element, index_array);
    find_replace(first_element,index_array[second_element][0], index_array);
}