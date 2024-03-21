# Modern C - Challenges

The folder comprises solutions to the first 9 'Challenges' from the textbook 'Modern C' (*Gustedt, J. (2019). Modern C. Manning Publications.*)

A summary of each of the challenges is listed below  in reverse order (including the question posed in the textbook, in *italics*), so as to describe the more involved challenges first. 

As you will see, each Challenge sub-folder has its own README file which explains the solution in detail, as well as explaining the source code and providing instructions on how to produce and run the executable for that Challenge.

Each Challenge has its own custom Makefile so that each executable can be compiled and run from Challenge sub-directory using the *make* command.



## Challenge 9 - Factorization

This program accepts a list of positive integers at the command line, calculates the prime factors of each of those integers (and their corresponding exponents), then prints out each prime factorization

### Question Posed

    "Now that we’ve covered functions, see if you can implement a program 'factorization' that receives a number N on the command line and prints out:    
  
    N: F0 F1 F2 ...  
  
    where F0 and so on are all the prime factors of N.  
  
    The core of your implementation should be a function that, given a value of type size_t, returns its smallest prime factor.  

    Extend this program to receive a list of such numbers and output such a line for each of them." 



## Challenge 8 - Shortest Path

This program implements a breadth-first search algorithm on a graph to find the shortest distance between two vertices (supplied by user as command line arguments). The source vertex for the breadth first search is the vertex supplied in the first command line argument. If the vertices are connected, the program will print to the console the shortest distance between these vertices - else will state that the vertices are not connected.

### Question Posed

    "Extend the idea of an adjacency matrix of a graph G to a distance matrix D that holds the distance when going from point i to point j. Mark the absence of a direct arc with a very large value, such as SIZE_MAX.

    Can you find the shortest path between two nodes x and y given as an input?" 

## Challenge 7 - Adjacency-Matrix

This program implements a breadth-first search algorithm on a graph to find its connected components and a corresponding 'spanning forest' (a forest comprised of a spanning tree for each connected component). 

### Question Posed

    "The adjacency matrix of a graph G is a matrix A that holds a value true or false in element A[i][j] if there is an arc from node i to node j.

    At this point, can you use an adjacency matrix to conduct a breadth-first search in a graph G? Can you find connected components? Can you find a spanning tree?"


## Challenge 6 - Linear Algebra

This programme implements a computationally efficient algorithm for finding matrix inverses, using Gaussain elimination.

Concretely, the programme performs Gaussian Elimination row operations on a matrix (and its corresponding elementary matrix), until the matrix is in row reduced upper echelon form.

If that form is the identity matrix, the program will also have found the matrix inverse, having performed the same Gaussian Elimination steps on the elementary matrix. 

### Question Posed

    "The adjacency matrix of a graph G is a matrix A that holds a value true or false in element A[i][j] if there is an arc from node i to node j.

    At this point, can you use an adjacency matrix to conduct a breadth-first search in a graph G? Can you find connected components? Can you find a spanning tree?"


## Challenge 5 - Complex Numerical Derivatives

This program finds a numerical derivative for the complex sine function at a given point, by taking the limit along the real axis.

### Question Posed

    "Can you extend the derivative (Challenge 2) to the complex domain: that is, functions that receive and return double complex values?"


## Challenge 4 - Union-Find

This project implements a union-find algorithm in C using an index table . 

Concretely, the program creates an index table of a size chosen by the user via a command line argument.

The program then proceeds to perform a prescribed number of operations on the set, in order to demonstrate the union find algorithm in action.


### Question Posed

    "The Union-Find problem deals with the representation of partitions over a base set. We will identify the elements of the base set using the numbers 0, 1, ... and will represent partitions with a forest data structure where each element has a “parent” that is another element inside the same partition. Each set in such a partition is identified by a designated element called the root of the set.

    We want to perform two principal operations:
    - A Find operation receives one element of the ground set and returns the root of the corresponding set.
    - A Union operation receives two elements and merges the two sets to which these elements belong into one.

    Can you implement a forest data structure in an index table of base type size_t called parent? Here, a value in the table SIZE_MAX would mean a position repre- sents a root of one of the trees; another number represents position of the parent of the corresponding tree. One of the important features to start the implementation is an initialization function that makes parent the singleton partition: that is, the partition where each element is the root of its own private set.

    With this index table, can you implement a Find function that, for a given index, finds the root of its tree?
    Can you implement a FindReplace function that changes all parent entries on a path to the root (including) to a specific value?
    Can you implement a FindCompress function that changes all parent entries to the root that has been found?
    Can you implement a Union function that, for two given elements, combines their trees into one? Use FindCompress for one side and FindReplace for the other."


## Challenge 3 - Pi Approximation

This program approximates the value of pi to a given number of decimal places using the Gauss-Legendre approximation.

### Question Posed

    "Compute the N first decimal places of π."


## Challenge 2 - Complex Numerical Derivatives

This program finds a numerical derivative for the cosine function at a point.

### Question Posed

    "Something we’ll deal with a lot is the concept of numerical algorithms. To get your hands dirty, see if you can implement the numerical derivative double f(double x) of a function double F(double x).

    Implement this with an example F for the function that you use for this exercise. A good primary choice for F would be a function for which you know the derivative, such as sin, cos, or sqrt. This allows you to check your results for correctness."

## Challenge 1 - Sorting Algorithms in C

This program implements the Merge Sort and Quick Sort algorithms in C

### Challenge Posed
    "Can you do:
        1 A merge sort (with recursion)
        2 A quick sort (with recursion)
    
    on arrays with sort keys such as double or strings to your liking?
    
    Nothing is gained if you don’t know whether your programs are correct. Therefore, can you provide a simple test routine that checks if the resulting array really is sorted?
    This test routine should just scan once through the array and should be much, much faster than your sorting algorithms."


