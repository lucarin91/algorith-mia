#include "bubbleSort.h"
#include "utility.h"
#include <vector>

using namespace std;

// Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly  
//  steps through the list to be sorted, compares each pair of adjacent items and swaps them if they  
//  are in the wrong order. The pass through the list is repeated until no swaps are needed, which 
//  indicates that the list is sorted.
void bubbleSort(std::vector<int> &A){
    int n = A.size();
    bool swapped = true;
    while(swapped){
        swapped = false;
        for (int i = 1; i < n; ++i)
        {
            if (A.at(i-1) > A.at(i))
            {
                swap(A, i-1, i);
                swapped = true;
            }
        }
    } 
}

// The bubble sort algorithm can be easily optimized by observing that the n-th pass finds 
//  the n-th largest element and puts it into its final place
//  More generally, it can happen that more than one element is placed in their final position 
//  on a single pass. In particular, after every pass, all elements after the last swap are sorted, 
//  and do not need to be checked again. This allows us to skip over a lot of the elements, resulting 
//  in about a worst case 50% improvement in comparison count (though no improvement in swap counts), 
//  and adds very little complexity because the new code subsumes the "swapped" variable
void bubbleSortOptimizing(std::vector<int> &A){
    int n = A.size();
    while(n){
        int newn = 0;
        for (int i = 1; i < n; ++i)
        {
            if (A.at(i-1) > A.at(i))
            {
                swap(A, i-1, i);
                newn = i;
            }
        }
        n = newn;
    }
}

// Cocktail sort is a variation of bubble sort that is both a stable sorting algorithm and a comparison sort
//  The algorithm differs from a bubble sort in that it sorts in both directions on each pass through the list.
//  The complexity of cocktail sort in big O notation is O(n^2) for both the worst case and the average case, 
//  but it becomes closer to O(n) if the list is mostly ordered before applying the sorting algorithm, for example, 
//  if every element is at a position that differs at most k (k >= 1) from the position it is going to end up in, 
//  the complexity of cocktail sort becomes O(k*n).
void cocktailSort( std::vector<int> &A){
    int begin = -1, 
        end = A.size() - 2;

    bool swapped = true;
    while(swapped){
        swapped = false;
        begin++;
        for (int i = begin; i <= end; ++i)
        {
            if (A.at(i) > A.at(i+1))
            {
                swap(A, i, i+1);
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        // decreases `end` because the elements after `end` are in correct order
        end--;
        for (int i = end; i >= begin; --i)
        {
            if (A.at(i) > A.at(i+1))
            {
                swap(A, i, i+1);
                swapped = true;
            }
        }
    }
}