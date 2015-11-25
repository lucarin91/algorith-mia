#include "insertionSort.h"
#include <vector>

void insertionSort(std::vector<int> &A, int start, int end){

    for (int i = start+1; i < end; ++i)
    {
       int x = A.at(i);
       int j = i;
       while(j > start && A.at(j-1) > x){
            A.at(j) = A.at(j-1);
            j--;
        }
        A.at(j) = x;
    }
}