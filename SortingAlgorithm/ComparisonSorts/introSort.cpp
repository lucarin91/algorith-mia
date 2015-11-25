#include "introSort.h"
#include "quickSort.h"
#include "heapSort.h"
#include "utility.h"
#include <vector>
#include <math.h>       /* floor */

using namespace std;



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