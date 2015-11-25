#include "gnomeSort.h"
#include "utility.h"
#include <vector>

// Gnome sort (or Stupid sort) is a sorting algorithm originally proposed by 
//  Dr. Hamid Sarbazi-Azad (Professor of Computer Engineering at Sharif University 
//  of Technology) in 2000 and called "stupid sort" (not to be confused with bogosort),
//  and then later on described by Dick Grune and named "gnome sort" from the observation
//  that it is "how a gnome sorts a line of flower pots." It is a sorting algorithm
//  which is similar to insertion sort, except that moving an element to its proper place
//  is accomplished by a series of swaps, as in bubble sort. It is conceptually simple, 
//  requiring no nested loops. The average, or expected, running time is O(n^2), but tends 
//  towards O(n) if the list is initially almost sorted

void gnomeSort(std::vector<int> &A){
    int pos = 1;
    while(pos < A.size()){
        if (A[pos] >= A[pos-1])
        {
            pos++;
        } else {
            swap(A, pos, pos-1);
            if (pos > 1)
            {
                pos--;
            }
        }
    }
}

void gnomeSortOptimized(std::vector<int> &A){
    int pos = 1,
        last = 0;
    while(pos < A.size()){
        if (A[pos] >= A[pos-1]){
            if(last != 0)
            {
                pos = last;
                last = 0;
            }
            pos++;
        } else {
            swap(A, pos, pos-1); 
            if (pos > 1){
                if (last == 0)
                    last = pos;
                pos--;
            } else{
                pos++;
            }
        }
    }
}