#include "standardlibs.h"

#ifndef CUSTOM_STRUCTS
#define CUSTOM_STRUCTS

#define GRAPH_SIZE 11

typedef struct spanning_tree spanning_tree;
struct spanning_tree {
    size_t source_vertex;
    size_t vertex_distances[GRAPH_SIZE];
};

typedef struct exploration_forest exploration_forest;
struct exploration_forest {
    char colours[GRAPH_SIZE];
    size_t explored_vertices;
    size_t connected_components;
    size_t source_vertices[GRAPH_SIZE];
    bool forest_graph[GRAPH_SIZE][GRAPH_SIZE];
};

typedef struct breadth_queue breadth_queue;
struct breadth_queue {
    size_t queue_source_vertex;
    size_t queue[GRAPH_SIZE];
    size_t queue_start;
    size_t queue_end;
    size_t iteration_counter;
    size_t layer_tracker[GRAPH_SIZE];
    size_t current_layer;
};
#endif