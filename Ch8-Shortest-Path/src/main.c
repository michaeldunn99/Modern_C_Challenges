#include "standardlibs.h"
#include "structures.h"
#include "helper-functions.h"
#include "exploration_queue.h"



/**
 * @brief Main function that calculates the shortest path between two vertices in a graph.
 * 
 * The graph is defined below and is the same adapted graph from the previous challenge (Ch7-Adjacency-Matrix).
 * 
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 * @return int The exit status of the program.
 */
int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 3) {
        printf("Usage: %s <n_1>, <n_2> where 0<=n_1,n_2 <=%d and <n_1> != <n_2>\n", argv[0], GRAPH_SIZE-1);
        return 1;
    }

    // Validate the input arguments
    if (validate_input(argv[1]) || validate_input(argv[2])) {
        return 1;
    }

    // Convert the input arguments to integers
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);

    // Check if the two vertices are the same
    if (n1 == n2) {
        printf("<n_1> != <n_2>\n");
        return 1;
    }

    // Define the graph as a static 2D array
    bool graph_static[GRAPH_SIZE][GRAPH_SIZE] = {
        /*    0   1  2  3  4  5  6  7  8  9  10*/
        /*0 */{0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        /*1 */{1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        /*2 */{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        /*3 */{0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        /*4 */{0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0},
        /*5 */{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        /*6 */{0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0},
        /*7 */{0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
        /*8 */{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        /*9 */{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        /*10*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    };

    // Allocate memory for the dynamic graph
    bool **graph = malloc(sizeof(bool*) * GRAPH_SIZE);

    // Initialize the exploration forest
    exploration_forest* my_forest = initialize_exploration_forest();

    // Copy the graph from static memory into dynamic memory
    for (size_t i = 0; i < GRAPH_SIZE; ++i) {
        graph[i] = malloc(sizeof(bool) * GRAPH_SIZE);
        for (size_t j = 0; j < GRAPH_SIZE; ++j) {
            graph[i][j] = graph_static[i][j];
        }
    }
    
    // Initialize the source and target vertices based on user input
    size_t source = n1;
    size_t target = n2;

    // Initialize the first spanning tree based on the source vertex entered
    spanning_tree* current_spanning_tree = malloc(sizeof(spanning_tree));

    // Allocate memory for the queue
    breadth_queue* curr_queue = malloc(sizeof(breadth_queue));
    if (curr_queue == NULL) {
        printf("Memory could not be allocated for queue\n");
        exit(-1);
    }
    
    // Call the functions to initialize the queue and the spanning tree
    initialize_queue(curr_queue, source);
    initialize_spanning_tree(current_spanning_tree, source);

    // Call the function to explore the connected component of the source vertex entered
    explore_tree(graph, my_forest, current_spanning_tree, curr_queue);

    // Call the function to print the distance between the two vertices (or state that they are not connected)
    print_distances(current_spanning_tree, source, target);

    // Free the dynamically allocated variables
    free_variables(graph, curr_queue, current_spanning_tree, my_forest);
}
    



