#include "exploration_queue.h"

/**
 * Initializes an exploration forest (see 'definitions.h' for the formal structure definition - the information stored is described informally below)
 * 
 * This is a data structure that keeps track of the vertices that have been explored and the edges that have been
 * added to the spanning tree of each connected component of the graph (according to the breadth-first search algorithm).
 * 
 * The edges are stored in an adjacency matrix, where a 1 in position (i, j) indicates that there is an edge between vertices i and j.
 * 
 * The structure also holds the number of connected components in the graph and the source vertices of each connected component, as well
 * as the colours of the vertices as they are explored (i.e. whether they are white, grey or black - at the end of the algorithm, each vertex will be black).
 * 
 * Storing the colours is useful as we can continue to explore the graph by conducting breadth-first search (on new connected components) 
 * until all vertices have been explored.
 * 
 * @return A pointer to the initialized exploration forest.
 */
exploration_forest* initialize_exploration_forest(void) {

    //Allocate memory for the exploration forest
    exploration_forest* forest_init = malloc(sizeof(exploration_forest));
    if (forest_init == NULL) {
        printf("Memory could not be allocated for exploration forest\n");
        exit(-1);
    }

    //Set Number of explored vertices to 0
    forest_init->explored_vertices = 0;

    //Set Number of connected components to 0
    forest_init->connected_components = 0;
    
    //Initialy set all vertices to be white and source vertices attribute to be SIZE_MAX in all positions 
    for (size_t i = 0; i < GRAPH_SIZE; ++i) {
        (forest_init->colours)[i] = 'w';
        (forest_init)->source_vertices[i] = SIZE_MAX;
        for (size_t j = 0; j < GRAPH_SIZE; ++j) {
            //Set all edges to be 0 initially (i.e. no edges have been explored yet)
            (forest_init)->forest_graph[i][j] = 0;
        }
    }
    return forest_init;
}


/**
 * Initializes a spanning tree with the given source vertex.
 * 
 * Note here that 'layer' means all the vertices that are at a certain distance from the source vertex 
 * (i.e. layer 0 is the source vertex, layer 1 is all the vertices that are adjacent to the source vertex, 
 * layer 2 is all the vertices that are adjacent to the vertices in layer one and are not in any of the previous layers), and so on).
 * 
 * Here 'iteration counter' is the number of vertices that have been explored in the current layer
 * 
 * The spanning tree stores the smallest distance of each vertex in the connected component from the source vertex.
 * 
 * @param current_spanning_tree The current spanning tree to be initialized (according to the connected component in which the source vertex belongs).
 * @param source The source vertex for the spanning tree.
 * @return The initialized spanning tree.
 */
spanning_tree* initialize_spanning_tree(spanning_tree* current_spanning_tree, size_t source) {
    current_spanning_tree->source_vertex = source;
    
    //Set the distance of the source vertex from itself to be 0 and all other vertices to be SIZE_MAX (i.e. infinity - no edges have been explored yet)
    for (size_t i = 0; i < GRAPH_SIZE; ++i) {
        if (i == source) {
            (current_spanning_tree->vertex_distances)[i] = 0;
        } else {
            (current_spanning_tree->vertex_distances)[i] = SIZE_MAX;
        }
    }
    return current_spanning_tree;
}

/**
 * Recursive function that explores a spanning tree of the connected component of the source vertex, 
 * according to the breadth-first search algorithnm starting from the source vertex.
 * 
 * @param graph The original adjacency matrix representing the original graph (provided in main.c and 
 *              taken from P557, Introduction to Algortithms (4th Edition) a.k.a 'CLRS').
 * @param explor_forest The exploration forest containing the colors of the vertices and forest graph.
 * @param current_spanning_tree The current spanning tree of the connected component of the source vertex.
 * @param curr_queue The breadth-first search queue of the connected component of the source vertex.
 * @return Always returns 0, indicating that the function has completed successfully.
 */
int explore_tree(bool** graph, exploration_forest* explor_forest, spanning_tree* current_spanning_tree, breadth_queue* curr_queue) {
    size_t vertices_found = 0;

    //Recursive termination condition: if the queue is empty, then the search is complete
    if (curr_queue->queue_start == curr_queue->queue_end) {
        return 0;
    }

    //Iterate through the vertices of the graph to find the vertices that are adjacent to the current vertex at the start of the queue
    for (size_t j = 0; j < GRAPH_SIZE; ++j) {
        if (graph[(curr_queue->queue)[(curr_queue->queue_start)]][j] == 1 && (explor_forest->colours)[j] == 'w') {

            //If the vertex found is white, then it is adjacent to the current vertex, has not been found yet, and so it is added to 'vertices found' count
            ++vertices_found;

            //Add the edge between the current vertex and the vertex found to the forest graph and enqueue the vertex found (i.e. add it to the queue)
            explor_forest->forest_graph[(curr_queue->queue)[(curr_queue->queue_start)]][j] = 1;
            explor_forest->forest_graph[j][(curr_queue->queue)[(curr_queue->queue_start)]] = 1;
            enqueue(j, explor_forest, current_spanning_tree, curr_queue);
        }
    }

    //Update the layer tracker (in the layer above the current layer) with the number of vertices that were found by exploring the current vertex (since the vertices found are in the next layer of the graph)
    curr_queue->layer_tracker[(curr_queue->current_layer) + 1] += vertices_found;

    //Dequeue the current vertex
    dequeue_first_entry(explor_forest, curr_queue);

    //Add one to the iteration counter (iteration counter counts the vertices that have been explored in the current layer )
    ++(curr_queue->iteration_counter);

    //If you have explored each of the vertices to be explored in the current layer, then move to the next layer and reset the iteration counter to 0
    if ((curr_queue->iteration_counter) == curr_queue->layer_tracker[(curr_queue->current_layer)] && curr_queue->layer_tracker[(curr_queue->current_layer)]) {
        curr_queue->iteration_counter = 0;
        ++(curr_queue->current_layer);
    }

    //Recursively call the function to explore the next vertex in the queue
    explore_tree(graph, explor_forest, current_spanning_tree, curr_queue);
    return 0;
}

/**
 * Enqueues a vertex into the breadth-first search queue.
 *
 * @param vertex The vertex to enqueue.
 * @param explor_forest The exploration forest (Forest of spanning trees generated by breadth-first search on each connected component of the graph)
 * @param current_spanning_tree The current spanning tree being built (i.e. based on the connected component of the current source vertex).
 * @param curr_queue The breadth-first search queue.
 */
void enqueue(size_t vertex, exploration_forest* explor_forest, spanning_tree* current_spanning_tree, breadth_queue* curr_queue) {

    //Set the new end of the queue (circular queue implementation)
    size_t new_end = ((curr_queue->queue_end)+1) % GRAPH_SIZE;

    //If the new end of the queue is the same as the start of the queue, then the queue is full so we cannot add another item - this is an error
    if (new_end == curr_queue->queue_start) {
        printf("Error: Queue is full - cannot add another item\n");
        exit(-1);
    }

    //Add the vertex to the queue
    curr_queue->queue[curr_queue->queue_end] = vertex;

    //The vertex is now grey
    (explor_forest->colours)[vertex] = 'g';

    //The vertex is now part of the current spanning tree and the distance from the source vertex is updated according to the current layer of the search
    (current_spanning_tree->vertex_distances)[vertex] = (curr_queue->current_layer)+1;
    
    //Update the position of the end of the queue
    curr_queue->queue_end = new_end;
}

/**
 * Dequeues the first entry in the breadth-first search queue.
 *
 * @param explor_forest The exploration forest (Forest of spanning trees generated by breadth-first search on each connected component of the graph)
 * @param curr_queue The breadth-first search queue.
 */
void dequeue_first_entry(exploration_forest* explor_forest, breadth_queue* curr_queue) {
    //Set the new start of the queue (circular queue implementation)
    size_t new_start = ((curr_queue->queue_start)+1) % GRAPH_SIZE;

    //If the start of the queue is the same as the end of the queue, then the queue is empty so we cannot dequeue an item - this is an error
    if (curr_queue->queue_start == curr_queue->queue_end) {
        printf("Error: Queue is empty - cannot dequeue an empty queue\n");
        exit(-1);
    }

    //The item being dequeued now becomes black
    explor_forest->colours[curr_queue->queue[curr_queue->queue_start]] = 'b';

    //Add the vertex to the list of explored vertices (since we have now dequeued it from the queue and it is black, it is now considered explored)
    ++explor_forest->explored_vertices;

    //Update the value in the queue at the previous start position to be SIZE_MAX (i.e. the queue is now empty at this position)
    curr_queue->queue[curr_queue->queue_start] = SIZE_MAX;

    //Update the position of the start of the queue position
    curr_queue->queue_start = new_start;
}

/**
 * Initializes the breadth-first search queue.
 *
 * @param queue_init The queue to initialize.
 * @param source The source vertex to initialize the queue with.
 */

void initialize_queue(breadth_queue* queue_init, size_t source) {

    //Set the source vertex of the queue
    queue_init->queue_source_vertex = source;

    //Set the start of the queue to be position 0
    queue_init->queue_start = 0;

    //Set the end of the queue to be position 1
    queue_init->queue_end = 1;

    //Set the source vertex as the first item in the queue (i.e. in position 0 of the queue array)
    queue_init->queue[queue_init->queue_start] = source;

    //Set the iteration counter to 0
    queue_init->iteration_counter = 0;

    //Set the current layer of the search to be 0
    queue_init->current_layer = 0;

    //Set the number of vertices in the current layer to be 1 (since the source vertex is the only vertex in the first layer)
    (queue_init->layer_tracker)[0] = 1;
    for (int i = 1; i < GRAPH_SIZE; ++i) {
        //Set the number of vertices in every other layer to be 0 (since we have not yet explored any other vertices in the graph yet)
        (queue_init->layer_tracker)[i] = 0;
        if (i) {
            //Set the rest of the queue to be SIZE_MAX (i.e. the queue is currently empty at these positions)
            queue_init->queue[i] = SIZE_MAX;
        }
    } 
}