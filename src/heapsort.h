/****************************************************************************
*
 * Speed of classical sort algorithms
 *  quicksort
 *  merge sort
 * in-place merge sort
 * heapsort

 speed, total number of comparison and movement are normalized by n*log2(n)

Copyright (C) 2011 Dongxu Li (dongxuli2011@gmail.com)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**********************************************************************/
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
    void doQuickSort();
    void doQuickSort(unsigned int low,unsigned int high);
    void quickSortPartition(unsigned int low,unsigned int high, unsigned int& pivot );
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
