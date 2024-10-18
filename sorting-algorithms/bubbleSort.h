#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include "printVec.h"

template<typename Comparable>
vector<Comparable> bubbleSort(vector<Comparable> vec, int& reads, int& writes) {
    reads = 0;
    writes = 0;
    int numPasses = 0, i;
    Comparable temp;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            if (vec[i] > vec[i+1]){

                temp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = temp;

                // Each Swap has 3 writes and 2 Reads
                writes += 3;
                reads += 2;

                // Update haveSwapped
                haveSwapped = true;
            }

            //read and compare two indices
            reads += 2;
        }
        // Update numPasses
        ++numPasses;

        // Uncomment this line if you want to see each iteration
        //printVec(vec);
    }
    return vec;
}

#endif
