# Union-Find

This project implements a union-find algorithm using an index table in C. 

Concretely, the program creates an index table of a size chosen by the user via a command line argument.

The program then proceeds to perform a prescribed number of operations on the set, in order to demonstrate the union find algorithm in action.


## Challenge Posed

    "The Union-Find problem deals with the representation of partitions over a base set. We will identify the elements of the base set using the numbers 0, 1, ... and will represent partitions with a forest data structure where each element has a “parent” that is another element inside the same partition. Each set in such a partition is identified by a designated element called the root of the set.

    We want to perform two principal operations:
    - A Find operation receives one element of the ground set and returns the root of the corresponding set.
    - A Union operation receives two elements and merges the two sets to which these elements belong into one.

    Can you implement a forest data structure in an index table of base type size_t called parent? Here, a value in the table SIZE_MAX would mean a position repre- sents a root of one of the trees; another number represents position of the parent of the corresponding tree. One of the important features to start the implementation is an initialization function that makes parent the singleton partition: that is, the partition where each element is the root of its own private set.

    With this index table, can you implement a Find function that, for a given index, finds the root of its tree?
    Can you implement a FindReplace function that changes all parent entries on a path to the root (including) to a specific value?
    Can you implement a FindCompress function that changes all parent entries to the root that has been found?
    Can you implement a Union function that, for two given elements, combines their trees into one? Use FindCompress for one side and FindReplace for the other."

## Description

This program accepts an integer command line argument and creates an index table of that size, where each element in the table is its own parent.

The program then conducts the following operations, and prints out the result after each:
1. Replace the every parent in the tree below the 4th element with the 5th element (including the root) and print the result

2. Replace the every parent in the tree below the 3rd element with the 4th element (including the root) and print the result

3. Set the parent of the 2nd element to the 3rd element
    
4. Set the parent of the 0th element to the third element and print the result

5. Set the parent of the 5th element to the 6th element and print the result

6. Compress every node in the tree below the 0th element to point to the root and print the result

7. Set the parent of the 3rd element to the 1st element and print the result

8. Combine the sets containing the trees of the 0th and 1st elements respectively and print the result

## Usage

1. Navigate to the Challenges/Ch4-Union-Find folder

2. To compile run:

    ```bash
    make union-find
    ```

3. To execute, run:

    ```bash
    ./bin/union-find [n]
    ```

    where [n] is a positive integer greater than 6.

