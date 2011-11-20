#ifndef HEAPSORT_H
#define HEAPSORT_H
#include<vector>

class heapSort
{
public:
    //    heapSort();
    heapSort(unsigned int n);
    //    void setArrary(const <unsigned int>& a);
    void initializeRandom();
    void init();
    void resize(unsigned int n);
    void randomnize();
    void doHeapSort();
    void doMergeSort();
    void doMergeInPlaceSort();
    void doMergeInPlaceSort(unsigned int low,unsigned int length);
    void mergeSingle(unsigned int low,unsigned int length);
    void mergeInPlace(unsigned int iP1, unsigned int lengthP1,unsigned int iQ,unsigned int lengthQ);
    void printArray();
    void print();
    long int getTotalComparison();
    long int getTotalMovement();

private:
    bool randomInitialized;
    long int totalComparison;
    long int totalMovement;
    std::vector<unsigned int> array;
    std::vector<unsigned int> arrayBuffer; //extra space used by standard merge sort
};

#endif
// HEAPSORT_H
