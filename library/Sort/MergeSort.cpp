/*
  O(n log n)
*/

#include <iostream>
#include <vector>

using namespace std;

template<class T>
void MergeSort(vector<T> &A)
{
    int n = (int)A.size();
 
    if (n <= 1) return;
    vector<T> L(A.begin(), A.begin() + n / 2);
    vector<T> R(A.begin() + n / 2, A.end());
 
    MergeSort(L);
    MergeSort(R);
 
    int l = (int)L.size(), r = (int)R.size();
    for (int i = 0, j = 0, k = 0; i < n; i++) {
	if (k == r) {
	    A[i] = L[j++];
	} else if(j == l) {
	    A[i] = R[k++];
	} else if(L[j] <= R[k]) {
	    A[i] = L[j++];
	} else {
	    A[i] = R[k++];
	}
    }
}
