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
        HeapSort,
        QuickSort
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
