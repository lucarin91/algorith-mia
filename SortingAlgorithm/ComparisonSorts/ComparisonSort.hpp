#if !ComparisonSort_hpp_
#define ComparisonSort_hpp_
#include <iostream>
#include <vector>
#include <math.h> /* floor */

using namespace std;

namespace CoroAlg {
struct ComparisonSort {
  static void bubbleSort(vector<int>&);
  static void bubbleSortOptimizing(vector<int>&);
  static void cocktailSort(vector<int>&);

  static void gnomeSortOptimized(vector<int>&);
  static void gnomeSort(vector<int>&);

  static void heapsort(vector<int>&,
                       int start,
                       int count);

  static void insertionSort(std::vector<int>&,
                            int  start,
                            int  end);

  static void introSort(std::vector<int>&);

  static int  partition(std::vector<int>&,
                        int  lo,
                        int  hi);
  static void quicksort(std::vector<int>&,
                        int  lo,
                        int  hi);
  static void quickSortDualPivotYaroslavskiy(std::vector<int>&,
                                             int  left,
                                             int  right);
  static void quickSortAlternative(std::vector<int>&,
                                   int  lo,
                                   int  hi);

private:
  static void siftDown(std::vector<int>&, int start, int end);
  static void heapify(std::vector<int>&, int count);
  static void introsort_aux(std::vector<int>&, int start, int end, int maxdepth);

  static void swap(std::vector<int>& A, int a, int b) {
    int temp = A[b];
    A[b] = A[a];
    A[a] = temp;
  }
};
}
#endif // if !ComparisonSort_hpp_
