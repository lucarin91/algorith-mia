#include "ComparisonSort.hpp"

namespace CoroAlg{
void ComparisonSort::insertionSort(std::vector<int> &A, int start, int end){

    for (int i = start+1; i < end; ++i)
    {
       int x = A[i];
       int j = i;
       while(j > start && A[j-1] > x){
            A[j] = A[j-1];
            j--;
        }
        A[j] = x;
    }
}
}
