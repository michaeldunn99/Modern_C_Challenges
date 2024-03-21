#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include"test-functions.h"

//Declare the merge-sort function
int merge_sort(int start, int end,  void** arr, int (*compare)(void*, void*));

#endif // MERGE-SORT_H