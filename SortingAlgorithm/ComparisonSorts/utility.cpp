#include "utility.h"
#include <vector>

void swap(std::vector<int> &A, int a, int b){
    int temp = A.at(b);
    A.at(b) = A.at(a);
    A.at(a) = temp;
}