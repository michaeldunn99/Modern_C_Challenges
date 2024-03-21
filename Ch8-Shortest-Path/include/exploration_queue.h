#include "standardlibs.h"
#include "structures.h"

#ifndef EXPLORATION_QUEUE_H
#define EXPLORATION_QUEUE_H

exploration_forest* initialize_exploration_forest(void);
spanning_tree* initialize_spanning_tree(spanning_tree* current_spanning_tree, size_t source);
int explore_tree(bool**graph, exploration_forest* explor_forest, spanning_tree* current_spanning_tree, breadth_queue* curr_queue);
void enqueue(size_t vertex, exploration_forest* explor_forest, spanning_tree* current_spanning_tree, breadth_queue* curr_queue);
void dequeue_first_entry(exploration_forest* explor_forest, breadth_queue* curr_queue);
void initialize_queue(breadth_queue* queue_init, size_t source);

#endif