#include "standardlibs.h"
#include "structures.h"

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

int validate_input(char* arg);
void free_variables(bool** graph, breadth_queue* curr_queue, spanning_tree* current_spanning_tree, exploration_forest* my_forest);
void print_distances(spanning_tree* current_spanning_tree, size_t source);
void print_forest_graph(exploration_forest* explor_forest);
void print_graph(bool** graph);
void print_result(bool** graph, exploration_forest* my_forest, spanning_tree* current_spanning_tree, breadth_queue* curr_queue);

#endif