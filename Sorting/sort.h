/* Each of the algorithms only make use of "<" for comparison. 
 * Either of the following has to be true :-
 * a < b
 * b < a
 * !(a < b) && !(b < a)
 *
 * This allows us to sort any data type given some definition of '<' operator
 */
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

template<class T> static void merge (vector<T>& v, const int& l, 
                                     const int& mid, const int& u);
template <class T> void mergeSort (vector<T>& v);
template <class T> void quickSort (vector<T>& v);
template <class T> void heapSort (vector<T>& v);

#include <mergeSort.cpp>
#include <quickSort.cpp>
#include <heapSort.cpp>
