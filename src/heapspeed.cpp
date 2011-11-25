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
*********************************************************************
  * Compare speed, complexity of sorting algorithms
  * quicksort, merge sort, in-place merge sort, and heapsort
 *
  * */
#include <iostream>
#include <vector>

#include"actionFactory.h"
#include"linkedlist.h"

int main() {
    linkedList ls(100);
    ls.randomnize();
    std::cout<<ls<<std::endl;
    ls.mergeSort();
    std::cout<<ls<<std::endl;
    exit(0);
//    heapSort hs0(10);
//    hs0.doQuickSort();
//    hs0.printArray();
//    exit(0);
    actionFactory af(actionFactory::MergeSort);
    std::vector<actionFactory::SortType> aTypes={
        actionFactory::MergeSort,
        actionFactory::InPlaceMergeSort,
        actionFactory::HeapSort,
        actionFactory::QuickSort
    };
    for(auto it =aTypes.begin();it!=aTypes.end();it++){
        af.setType(*it);
        af.run(20);
    }

    return 0;



}
