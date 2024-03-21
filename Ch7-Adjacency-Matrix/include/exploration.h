#include "standardlibs.h"
#include "structures.h"
#include "queue.h"

#ifndef EXPLORATION_H
#define EXPLORATION_H

exploration_forest* initialize_exploration_forest(void);
spanning_tree* initialize_spanning_tree(spanning_tree* current_spanning_tree, size_t source);
int explore_tree(bool**graph, exploration_forest* explor_forest, spanning_tree* current_spanning_tree, breadth_queue* curr_queue);
int explore_graph(size_t source, bool** graph, exploration_forest* explor_forest, spanning_tree* current_spanning_tree, breadth_queue* curr_queue);

#endif