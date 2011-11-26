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
#include <iostream>
#include <cmath>
#include "heapsort.h"
#include "actionFactory.h"
#include "actionFactory.h"
#include "timediff.h"

statistics::statistics():sum(0.),sumOfSquared(0.),counts(0){
}

void statistics::add(double data){
    sum += data;
    sumOfSquared += data*data;
    counts++;
}
void statistics::print(){
    if(counts>=2){
        double average=sum/counts;
        double average2=sumOfSquared/counts;
        double variance=counts/double(counts-1)*(average2 - average*average);
        std::cout<<" ( "<<average<<" , "<<variance<<" )";
    }else{
        std::cout<<" ( 0 , 0 )";
    }
}

actionFactory::actionFactory(SortType aType){
    setType(aType);
}
void actionFactory::setType(SortType aType){
    this->aType=aType;
    switch(aType){
    case MergeSort:
        std::cout<<"Standard MergeSort\n";
        fp= & heapSort::doMergeSort;
        break;
    case InPlaceMergeSort:
        std::cout<<"In-Place MergeSort\n";
        fp= & heapSort::doMergeInPlaceSort;
        break;
    case HeapSort:
        std::cout<<"Standard HeapSort\n";
        fp= & heapSort::doHeapSort;
        break;
    case QuickSort:
        std::cout<<"Standard QuickSort\n";
        fp= & heapSort::doQuickSort;
        break;
    case LinkedListMergeSort:
        std::cout<<"LinkedList MergeSort\n";
        fpList= & linkedList::mergeSort;
        break;
    default:
        std::cout<<"Unknown algorithm type, exit...\n";
        exit(0);
    }
}

void actionFactory::run(unsigned int repeat){
    statistics normalizedSpeed;
    statistics comparison;
    statistics movement;
    struct timeval t_start,t_end;
    if(aType==LinkedListMergeSort){
        //linked list
        linkedList ll0(1);

        unsigned int n=(1<<nmin);
        for(unsigned int j=nmin;j<=nmax;j++){
            ll0.resize(n);
            for(unsigned int i=0;i<repeat;i++){
                ll0.init();
                gettimeofday(&t_start,NULL);
                (ll0.*fpList)();//sorting process
                if(ll0.inOrder() == false) {
                    std::cout<<"sorting failed\n";
                }
                gettimeofday(&t_end,NULL);
                double t=t_end - t_start;
                double complexity=n*log2(n);
                normalizedSpeed.add(complexity/t);
                comparison.add(ll0.getTotalComparison()/complexity);
                //                movement.add(hs0.getTotalMovement()/complexity);
            }
            std::cout<<"2^"<<j;
            normalizedSpeed.print();
            comparison.print();
            //        movement.print();
            std::cout<<std::endl;
            n<<=1;
        }
        std::cout<<std::endl;
    }else{
        //array
        heapSort hs0(1);

        unsigned int n=(1<<nmin);
        for(unsigned int j=nmin;j<=nmax;j++){
            hs0.resize(n);
            for(unsigned int i=0;i<repeat;i++){
                hs0.init();
                gettimeofday(&t_start,NULL);
                (hs0.*fp)();//sorting process
                gettimeofday(&t_end,NULL);
                double t=t_end - t_start;
                double complexity=n*log2(n);
                normalizedSpeed.add(complexity/t);
                comparison.add(hs0.getTotalComparison()/complexity);
                movement.add(hs0.getTotalMovement()/complexity);
            }
            std::cout<<"2^"<<j;
            normalizedSpeed.print();
            comparison.print();
            movement.print();
            std::cout<<std::endl;
            n<<=1;
        }
        std::cout<<std::endl;
    }

}












