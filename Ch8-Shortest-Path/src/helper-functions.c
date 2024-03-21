#include "helper-functions.h"

/**
 * Validates the input argument.
 * 
 * @param arg The input argument to validate.
 * @return 1 if the input is invalid, 0 otherwise.
 */
int validate_input(char* arg) {
    if (!atoi(arg)) {
        printf("n must be a number\n");
        return 1;
    }
    int n = atoi(arg);
    if (n < 0 || n > GRAPH_SIZE-1) {
        printf("n must be between 0 and %d\n inclusive", GRAPH_SIZE-1);
        return 1;
    }
    return 0;
}

/**
 * Prints the distances between two vertices in the spanning tree.
 * 
 * @param current_spanning_tree The spanning tree.
 * @param source The source vertex.
 * @param target The target vertex.
 */
void print_distances(spanning_tree* current_spanning_tree, size_t source, size_t target) {
    if (current_spanning_tree->vertex_distances[target] != SIZE_MAX) {
            printf("The shortest path beteween vertex %zu and vertex %zu is of distance %zu\n", source, target, current_spanning_tree->vertex_distances[target]);
    } else {
        printf("Vertex %zu is not connected to vertex %zu\n", target, source);
    }
}

/**
 * Frees the dynamically allocated variables.
 * 
 * @param graph The graph matrix.
 * @param curr_queue The breadth-first search queue.
 * @param current_spanning_tree The spanning tree.
 * @param explor_forest The exploration forest.
 */
void free_variables(bool** graph, breadth_queue* curr_queue, spanning_tree* current_spanning_tree, exploration_forest* explor_forest) {
    for (int i = 0; i < GRAPH_SIZE; ++i) {
        free(graph[i]);
    }
    free(graph);
    free(curr_queue);
    free(current_spanning_tree);
    free(explor_forest);
}