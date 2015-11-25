#include "quickSort.h"
#include "insertionSort.h"
#include "utility.h"
#include <vector>
#include <math.h>       /* floor */
#include <iostream>

using namespace std;

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

//----------------------------------------------

void quickSortAlternative(std::vector<int> &A, int lo, int hi){
    while(hi - lo > 10){ // choose a "k"
        int r = hi-1; //pick the position of a good pivot, currently we choose the rightmost element
        swap(A, r, lo);
        int p = partition(A, lo, hi-1);
        if (p <= (lo + hi)/2)
        {
            quickSortAlternative(A, lo, p-1);
            lo = p + 1;
        } else {
            quickSortAlternative(A, p+1, hi);
            hi = p - 1;
        }
    }
    insertionSort(A, lo, hi);
}

//----------------------------------------------

void quickSortDualPivotSedgewick(std::vector<int> &A, int left, int right){
    if (right > left) {
        if (A[left] > A[right]) 
            swap(A, left, right);

        int p = A[left], 
            q = A[right],
            l = left + 1, 
            g = right - 1, 
            k = l;

        while (k <= g) {
            if (A[k] < p) {
                swap(A, k, l);
                l++;
            } else if (A[k] >= q) {
                while (A[g] > q && k < g) g--;
                swap(A, k, g);
                g--;
                if (A[k] < p) {
                    swap(A, k, l);
                    l++;
                }
            }
            k++;
        }
        l--; g++;

        swap(A, left, l); swap(A, right, g);

        quickSortDualPivotSedgewick(A, left, l - 1);
        quickSortDualPivotSedgewick(A, l + 1, g - 1);
        quickSortDualPivotSedgewick(A, g + 1, right);
    }
}