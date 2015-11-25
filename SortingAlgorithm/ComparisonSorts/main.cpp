#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <vector>
//#include <stdlib.h>     /* srand, rand */
#include <algorithm>    // std::sort

#include "ComparisonSort.hpp"

using namespace std;

int myRandom(){
  return rand() % 100 + 1; //tra 1 e 100
}

void printVector(std::vector<int> &v){
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// In computing, wall-clock time can also mean the actual time taken by a computer to complete a task.
//  It is the sum of three terms: CPU time, I/O time, and the communication channel delay
//  In contrast to CPU time, which measures only the time during which the processor is actively working
//  on a certain task, wall time measures the total time for the process to complete.
//  The difference between the two consists of time that passes due to programmed delays or waiting
//  for resources to become available
double get_wall_time(){
struct timeval time;
if (gettimeofday(&time,NULL)){
    //  Handle error
    return 0;
}
return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
double get_cpu_time(){
    return (double)clock() / CLOCKS_PER_SEC;
}
// ----------------------------------------------------------------------------------------------------

double wall0;
double cpu0;
double wall1;
double cpu1;

void checkTime(bool itCanBeAnything){
    if (!itCanBeAnything)
    {
        wall1 = 0;
        cpu1 = 0;
        wall0 = get_wall_time();
        cpu0  = get_cpu_time();
    } else {
        wall1 = get_wall_time();
        cpu1  = get_cpu_time();
        cout << "Wall Time = " << wall1 - wall0 << endl;
        cout << "CPU Time  = " << cpu1  - cpu0  << endl;
        cout << "---------------------------------------" << endl;
    }
}

//----------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
int main(int argc, char *argv[]){
    cout << "---------------------------------------" << endl;
    srand (time(NULL));
    int quanti = atoi(argv[1]);
    std::vector<int> b;

    std::vector<int> v;
    for (int i = 0; i < quanti; ++i)
    {
        v.push_back(myRandom());
    }

    //------------------------------------------------------------
    // std::sort has traditionally been implemented as an intro-sort. From a high-level point of
    //  view it means a relatively standard quick-sort implementation (with some median probing
    //  to avoid a O(n2) worst case) coupled with an insertion sort routine for small inputs. libc++
    //  implementation however is slightly different and closer to TimSort: it detects already sorted
    //  sequences in the inputs and avoid sorting them again, leading to an O(n) behavior on fully sorted
    //  input. It also uses optimized sort networks for small inputs.
    cout << "standardSortCpp O(n log n)" << endl;
    b = v;
    checkTime(0);
    sort (b.begin(), b.end());
    checkTime(1);
    //------------------------------------------------------------
    cout << "intro-sort O(n log n)" << endl;
    b = v;
    checkTime(0);
    CoroAlg::ComparisonSort::introSort(b);
    checkTime(1);
    //------------------------------------------------------------
    cout << "heapsort O(n log n)" << endl;
    b = v;
    checkTime(0);
    CoroAlg::ComparisonSort::heapsort(b, 0, b.size());
    checkTime(1);
    //------------------------------------------------------------
    cout << "quicksort O(n log n)" << endl;
    b = v;
    checkTime(0);
    CoroAlg::ComparisonSort::quicksort(b, 0, b.size()-1);
    checkTime(1);
    //------------------------------------------------------------
    cout << "Alternative Quicksort (with insertionSort) O(n log n)" << endl;
    b = v;
    checkTime(0);
    CoroAlg::ComparisonSort::quickSortAlternative(b, 0, b.size());
    checkTime(1);
    //------------------------------------------------------------
    cout << "Quicksort Dual Pivot O(n log n)" << endl;
    b = v;
    checkTime(0);
    CoroAlg::ComparisonSort::quickSortDualPivotYaroslavskiy(b, 0, b.size()-1);
    checkTime(1);
    //------------------------------------------------------------
    cout << "bubbleSort O(n^2)" << endl;
    b = v;
    checkTime(0);
    CoroAlg::ComparisonSort::bubbleSort(b);
    checkTime(1);
    // // //------------------------------------------------------------
    // cout << "bubbleSortOptimizing O(n^2)" << endl;
    // b = v;
    // checkTime(0);
    // bubbleSortOptimizing(b);
    // checkTime(1);
    // //------------------------------------------------------------
    // cout << "cocktailSort O(n^2)" << endl;
    // b = v;
    // checkTime(0);
    // cocktailSort(b);
    // checkTime(1);
}
