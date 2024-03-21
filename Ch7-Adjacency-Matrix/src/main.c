#include "standardlibs.h"
#include "structures.h"
#include "exploration.h"
#include "helper-functions.h"

int main(int argc, char *argv[]) {


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
     

    bool **graph = malloc(sizeof(bool*) * GRAPH_SIZE);

    //Initialize the exploration forest
    exploration_forest* my_forest = initialize_exploration_forest();
    // Copy graph from static memory into dynamic memory;
    for (size_t i = 0; i < GRAPH_SIZE; ++i) {
        graph[i] = malloc(sizeof(bool) * GRAPH_SIZE);
        for (size_t j = 0; j < GRAPH_SIZE; ++j) {
            graph[i][j] = graph_static[i][j];
        }
    }
    
    //Initialize the first source vertex to be vertex 1 (based on P557 CLRS 4th Edition)
    size_t source = 1;

    //Initialize the first tree based on the source vertex entered
    spanning_tree* current_spanning_tree = malloc(sizeof(spanning_tree));

    // Initialize the current queue
    breadth_queue* curr_queue = malloc(sizeof(breadth_queue));
    if (curr_queue == NULL) {
        printf("Memory could not be allocated for queue\n");
        exit(-1);
    }
    
    explore_graph(source, graph, my_forest, current_spanning_tree, curr_queue);

    print_result(graph, my_forest, current_spanning_tree, curr_queue);

    free_variables(graph, curr_queue, current_spanning_tree, my_forest);
}