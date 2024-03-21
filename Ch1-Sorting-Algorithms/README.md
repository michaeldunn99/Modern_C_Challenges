# Sorting Algorithms in C

"This program implements the Merge Sort and Quick Sort algorithms in C

## Challenge Posed
    Can you do

        1 A merge sort (with recursion)
        2 A quick sort (with recursion)
    
    on arrays with sort keys such as double or strings to your liking?
    
    Nothing is gained if you don’t know whether your programs are correct. Therefore, can you provide a simple test routine that checks if the resulting array really is sorted?
    
    This test routine should just scan once through the array and should be much, much faster than your sorting algorithms."

## Description

In this project, we implement various sorting algorithms in C. The following algorithms are implemented:
- Merge Sort
- Quick Sort

## Explanation of src files

- **merge-sort.c** : Applies merge-sort algorithms to an array (of void* pointers), based on the compare function that is passed as an argument to the function
- **quick-sort.c** : Applies merge-sort algorithms to an array (of void* pointers), based on the compare function that is passed as an argument to the function
- **main.c** : Defines two arrays, an array of doubles and an array of strings; calls merge-sort and quick-sort to solve each of the arrays respectively, and prints out the result.
- **test-functions.c** : Ensures that the arrays have been sorted correctly

## Compilation

This project uses the GCC compiler. To compile the code, navigate to the Challenges/Ch-1-Sorting-Algorithms folder within the project directory and run the following command:

```bash
make sort
```

## Usage

Once the *sort* executable has been compiled using the make command, it will be saved in the bin folder. To run the executable, run the command:

```bash
./bin/sort
```

## Areas to Develop & For Improvement
- Add timers to check the speed of each of the algorithms
- Implement a wider range of algorithms
- Run algorithms on a wider range of inputs
