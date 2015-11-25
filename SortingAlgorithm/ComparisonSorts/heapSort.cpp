#include "heapSort.h"
#include "utility.h"
#include <math.h>       /* floor */
#include <vector>

using namespace std;

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