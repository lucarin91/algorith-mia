#include "algorithmia.h"
#include <vector>
#include <math.h>       /* floor */
#include <iostream>

using namespace std;

void swap(std::vector<int> &A, int a, int b){
    int temp = A.at(b);
    A.at(b) = A.at(a);
    A.at(a) = temp;
}

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

// The heapsort algorithm involves preparing the list by first turning it into a max heap. 
//  The algorithm then repeatedly swaps the first value of the list with the last value, 
//  decreasing the range of values considered in the heap operation by one, and sifting 
//  the new first value into its position in the heap. This repeats until the range of 
//  considered values is one value in length

void siftDown(std::vector<int> &A, int start, int end){
    int root = start;
    while(root * 2 +1 <= end){
        int child = root * 2 + 1,
            swapV = root;
        if (A.at(swapV) < A.at(child))
        {
            swapV = child;
        }
        if (child+1 <= end && A.at(swapV) < A.at(child+1))
        {
            swapV = child+1;
        }
        if (swapV == root) return;
        else {
            swap(A, root, swapV);
            root = swapV;
        }
    }
}

void heapify(std::vector<int> &A, int count){
    int start = floor((count - 2) / 2);

    while(start >= 0){
        siftDown(A, start, count - 1);
        start--;
    }
}

void heapsort(std::vector<int> &A, int start, int count){
    // int count = A.size();
    heapify(A, count);
    int end = count -1;
    while(end > 0){
        swap(A, start, end);// swap(A, 0, end);
        end--;
        siftDown(A, start, end);// siftDown(A, 0, end);
    }
}

//Quicksort is a divide and conquer algorithm. Quicksort first divides a large array into 
//  two smaller sub-arrays: the low elements and the high elements. Quicksort can then 
//  recursively sort the sub-arrays.
//  The steps are:
//  - Pick an element, called a pivot, from the array.
//  - Reorder the array so that all elements with values less than the pivot come before
//      the pivot, while all elements with values greater than the pivot come after it 
//      (equal values can go either way). After this partitioning, the pivot is in its final 
//      position. This is called the partition operation.
//  - Recursively apply the above steps to the sub-array of elements with smaller values and
//       separately to the sub-array of elements with greater values.

int partition(std::vector<int> &A, int lo, int hi){
    int pivot = A.at(hi),
        i = lo;
    for (int j = lo; j < hi; ++j)
    {
        if (A.at(j) <= pivot)
        {
            swap(A, i, j);
            i++;
        }
    }
    swap(A, i, hi);
    return i;

}

void quicksort(std::vector<int> &A, int lo, int hi){
    if (lo < hi)
    {
        int p = partition(A, lo, hi);
        quicksort(A, lo, p - 1);
        quicksort(A, p + 1, hi);
    }
}

// Introsort or introspective sort is a hybrid sorting algorithm that provides both fast 
//  average performance and (asymptotically) optimal worst-case performance. It begins with 
//  quicksort and switches to heapsort when the recursion depth exceeds a level based on 
//  (the logarithm of) the number of elements being sorted. This combines the good parts of 
//  both algorithms, with practical performance comparable to quicksort on typical data sets 
//  and worst-case O(n log n) runtime due to the heap sort. Since both algorithms it uses are 
//  comparison sorts, it too is a comparison sort

// mine is not a good implementation tough

void introsort_aux(std::vector<int> &A, int start, int end, int maxdepth){
    int n = end - start;
    if (n <= 1) return;
    else if (maxdepth == 0)
    {
        heapsort(A, start, end);
    } else {
        int p = partition(A, start, end);
        introsort_aux(A, 0, p, maxdepth-1);
        introsort_aux(A, p+1, end, maxdepth-1);
    }
}

void introSort(std::vector<int> &A){
    int maxdepth = floor(log(A.size())) * 2;
    introsort_aux(A, 0, A.size()-1, maxdepth);
}