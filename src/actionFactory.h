#ifndef HEAPSPEED_H
#define HEAPSPEED_H
#include "heapsort.h"
#define nmin 20
#define nmax 25

class statistics {
    public:
    statistics();
    void add(double data);
    void print();
    private:
    double sum,sumOfSquared;
    unsigned int counts;
};

class actionFactory {
    public:
    enum SortType {
        MergeSort,
        InPlaceMergeSort,
        HeapSort
    };
    actionFactory(SortType aType);
    void setType(SortType aType);
    void run(unsigned int repeat = 10);
    private:
    SortType aType;
    void (heapSort::*fp)();
};

#endif
// HEAPSPEED_H
