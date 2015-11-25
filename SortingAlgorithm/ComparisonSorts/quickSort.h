#include <vector>

void quicksort(std::vector<int> &A, int lo, int hi);
int partition(std::vector<int> &A, int lo, int hi);
void quickSortAlternative(std::vector<int> &A, int lo, int hi);
void quickSortDualPivotSedgewick(std::vector<int> &A, int left, int right);