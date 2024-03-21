#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "test-functions.h"

int quick_sort(int start, int end, void** arr, int (*compare)(void*, void*));

#endif