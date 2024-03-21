#include "standardlibs.h"
#include "structures.h"

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

void free_variables(bool** graph, breadth_queue* curr_queue, spanning_tree* current_spanning_tree, exploration_forest* my_forest);
void print_distances(spanning_tree* current_spanning_tree, size_t source, size_t target);
int validate_input(char* arg);

#endif