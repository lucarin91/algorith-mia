#include <iostream>
#include <vector>

using namespace std;

void swap(std::vector<int> &A, int a, int b){
    int temp = A[b];
    A[b] = A[a];
    A[a] = temp;
}

// Stooge sort is a recursive sorting algorithm with a time complexity of O(n^2.7095...). 
//  The running time of the algorithm is thus slower compared to efficient sorting algorithms, 
//  such as Merge sort, and is even slower than Bubble sort, a canonical example of a fairly 
//  inefficient and simple sort

void stoogeSort(std::vector<int> &A, int i, int j){
    if (A[j] < A[i])
        swap(A, j, i);
    if (j - i + 1 > 2)
    {
        int t = (j - i + 1) / 3;
        stoogeSort(A, i, j-t);
        stoogeSort(A, i+t, j);
        stoogeSort(A, i, j-t);
    }
}

int main(){

    std::vector<int> A { 34, 23, 1, 35, 8, 54, 43, 12, 6, 56, 23 };
    stoogeSort(A, 0, A.size()-1);

    return 0;
}