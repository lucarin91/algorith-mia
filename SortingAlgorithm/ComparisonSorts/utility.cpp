#include "utility.h"
#include <vector>

void swap(std::vector<int> &A, int a, int b){
    int temp = A[b];
    A[b] = A[a];
    A[a] = temp;
}