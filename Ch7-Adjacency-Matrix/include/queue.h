#include "standardlibs.h"
#include "structures.h"

#ifndef QUEUE_FUNCTIONS_H
#define QUEUE_FUNCTIONS_H

void initialize_queue(breadth_queue* queue_init, size_t source);
void enqueue(size_t vertex, exploration_forest* explor_forest, spanning_tree* current_spanning_tree, breadth_queue* curr_queue);
void dequeue_first_entry(exploration_forest* explor_forest, breadth_queue* curr_queue);

#endif