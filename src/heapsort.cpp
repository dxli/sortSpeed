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
#include <string>
#include<fstream>
#include<string>
#include<vector>
#include<time.h>
#include<sys/time.h>
#include "heapsort.h"
#include "randomInit.h"

std::uniform_int_distribution<unsigned int> heapSort::distribution(0, RAND_MAX);
std::mt19937 heapSort::engine; // Mersenne twister MT19937
std::function<unsigned int()> heapSort::generator = std::bind(distribution, engine);
//heapSort::heapSort()
//{
//    array.clear();
//    initializeRandom();
//    init();
//}
heapSort::heapSort(unsigned int n){
//    initializeRandom();
    resize(n);
    randomnize();
    init();
}
//void heapSort::setArrary(const <unsigned int>& a){
//    array=a;
//}
//void heapSort::initializeRandom(){
////    static std::uniform_int_distribution<int> distribution(0, RAND_MAX);
////    static std::mt19937 engine; // Mersenne twister MT19937
////    static auto generator = std::bind(distribution, engine);
////    int random = generator();  // Generate a uniform integral variate between 0 and 99.
////    int random2 = distribution(engine); // Generate another sample directly using the distribution and the engine objects.

//}

void heapSort::resize(unsigned int n){
    array.resize(n);
}

void heapSort::init(){
    totalComparison=0;
    totalMovement =0;
    randomnize();
}

void heapSort::randomnize(){
    for(auto it=array.begin(); it != array.end(); it++) {
        *it = generator();
    }
}

long int heapSort::getTotalComparison(){
    return totalComparison;
}
long int heapSort::getTotalMovement(){
    return totalMovement;
}
void heapSort::printArray(){
    for(auto it=array.begin(); it != array.end(); it++) {
        std::cout<<" "<<*it;
    }
    std::cout<<std::endl;
}
void heapSort::print(){
    //    for(auto it=array.begin(); it != array.end(); it++) {
    //        std::cout<<" "<<*it;
    //    }
    //    std::cout<<std::endl;
    std::cout<<"Array.size()="<<array.size()<<" totalComparison="<<totalComparison<<" totalMovement="<<totalMovement<<std::endl;
}
//heap sort
void heapSort::doHeapSort(){
    //form a binary tree
    unsigned int length=array.size() -1;
    unsigned int high=length;
    //the binary tree,
    //          low = (high - 1) >> 1;
    //          high= (low<<1) +1;
    unsigned int low=(length -1 )>>1;
    while(length>0) {
        if ( high ) {//still forming the binary tree
            totalComparison++;
            if(array[low] < array[high]) {
                totalMovement++;
                std::swap(array[low],array[high]);
            } else {
                if (high & 0x1) {
                    low--;
                }
                high--;
                continue;
            }
        } else {//sorting phase, picking the largest element from the first place
            totalMovement++;
            std::swap(array[0],array[length]);
            length--;
        }

        //maintain the binary tree order from the changed position (high)
        unsigned int i1=high;
        unsigned int k= (i1<<1)+1;
        while(k<=length) {
            if(k+1<=length) {
                totalComparison++;
                if(array[k]<array[k+1]) k++;
            }
            totalComparison++;
            if(array[i1]<array[k]) {
                totalMovement++;
                std::swap(array[i1],array[k]);
                i1=k;
                k= (k<<1)+1;
            } else break;
        }
        if(high) {
            if(high & 0x1) low--;
            high--;
        }
    }
}


//Merge sort
void heapSort::doMergeSort(){
    arrayBuffer.resize(array.size());
    //non recursive version of merge sort
    bool copyBack=false;//whether it's needed to copy arrayBuffer back to array
    unsigned int subLength=1; // current block size to merge
    const unsigned int length=array.size();


    auto pA= & array;
    auto pB= & arrayBuffer;
    while(subLength < length) {
        //merging loop
        auto itB=pB->begin();
        unsigned int low1=0;
        unsigned int low2=subLength;
        while(low1<array.size()){
            unsigned int high1= std::min(low1+subLength,length);
            unsigned int high2= std::min(low2+subLength,length);
            while(low1<high1 && low2 < high2) {
                totalComparison++;
                if(pA->at(low1) <= pA->at(low2)){
                    *itB++ =pA->at(low1);
                    low1++;
                }else{
                    *itB++ =pA->at(low2);
                    low2++;
                }
            }
            if(low1 < high1) {
                while(low1<high1){
                    *itB++ = pA->at(low1++);
                }
            }else{
                while(low2<high2){
                    *itB++ = pA->at(low2++);
                }
            }
            low1=low2;
            low2 +=subLength;
        }
        totalMovement += length;
        std::swap(pA,pB);
        copyBack = ! copyBack;
        subLength <<=1;
    }
    if(copyBack){
        auto itA=array.begin();
        auto itB=arrayBuffer.begin();
        while(itA != array.end()){
            *itA++ = *itB++;
        }
        totalMovement += length;
    }

}
//Merge sort in place
void heapSort::doQuickSort(){
    //recursive version of in place merge sort
    doQuickSort(0,array.size()-1);
}

void heapSort::doQuickSort(unsigned int low,unsigned int high){
    //recursive version of in place merge sort
    if(low >= high) return;
    unsigned int pivot;
    quickSortPartition(low,high,pivot);
    if(pivot>low+1) doQuickSort(low,pivot-1);
    if(pivot+1<high) doQuickSort(pivot+1,high);
}

void heapSort::quickSortPartition(unsigned int low,unsigned int high, unsigned int& pivot){
    //partition
    //generate a valid pivot value
    pivot = low + static_cast<unsigned int>( double(high - low)*random()/RAND_MAX );
    totalMovement++;
    std::swap(array[pivot],array[high]);
    unsigned int index=low;
    for(unsigned int i=low;i<high;i++){
        totalComparison++;
        if( array[i]<array[high]) {
            std::swap(array[i],array[index]);
            totalMovement++;
            index++;
        }
    }
    totalMovement++;
    std::swap(array[high],array[index]);
    pivot=index;
}

//Merge sort in place
void heapSort::doMergeInPlaceSort(){
    //recursive version of in place merge sort
    doMergeInPlaceSort(0,array.size());

}

//Merge sort in place
void heapSort::doMergeInPlaceSort(unsigned int low,unsigned int length){
    //recursive version of in place merge sort
    if(length<=1) return;

    unsigned int length0= length>>1;
    unsigned int middle0= low + length-length0;
    unsigned int length1= (middle0 - low)>>1;
    //    unsigned int middle1=low + length1-1;//inclusive for P1
    //    std::cout<<"heapSort::doMergeInPlaceSort("<<low<<","<<length<<"): low="<<low<<" length1="<<length1<<" middle0="<<middle0<<" length0="<<length0<<std::endl;
    doMergeInPlaceSort(middle0,length0);
    //    printArray();
    while(length1>=1){
        doMergeInPlaceSort(low,length1);
        mergeInPlace(low,length1,middle0,length0);
        middle0 -= length1;
        length0 += length1;
        length1 = ((middle0-low)>>1) ;
        //    printArray();
    }
    //    std::cout<<"heapSort::doMergeInPlaceSort("<<low<<","<<length<<")(1): low="<<low<<" length1="<<length1<<" middle0="<<middle0<<" length0="<<length0<<std::endl;
    if(middle0 - low == 1)  {
        mergeSingle(low,length0);
    }
    //    printArray();
}

//only one un
void heapSort::mergeSingle(unsigned int low,unsigned int length) {
    unsigned int i=low;
    unsigned int j=i+1;
    unsigned int last=low+length;
    while(j<=last){
        totalComparison++;
        if(array[i]<=array[j]) break;
        totalMovement ++;
        std::swap(array[i],array[j]);
        i++;
        j++;
    }
}

//in-place merge
void heapSort::mergeInPlace(unsigned int iP1, unsigned int lengthP1,unsigned int iQ,unsigned int lengthQ)
{
    //    std::cout<<"heapSort::mergeInPlace("<<iP1<<" , "<<lengthP1<<" , "<<iQ<<" , "<<lengthQ<<")"<<std::endl;
    //check for sanity, work space must be able to hold P1
    //    std::cout<<"heapSort::mergeInPlace()\n";
    //    printArray();
    //    if(iP1 + (lengthP1<<1) >iQ ){
    //        std::cout<<"heapSort::mergeInPlace():work space must be able to hold P1\n";
    //        exit(0);
    //    }
    unsigned int low1=iP1;
    unsigned int high1=iP1+lengthP1;
    unsigned int low2=iQ;
    const unsigned int high2=iQ + lengthQ;
    unsigned int target=iQ - lengthP1;
    //merging
    while(low1<high1 && low2 < high2){

        totalComparison++;
        if(array[low1]<array[low2]){
            std::swap(array[target],array[low1]);
            target++;
            low1++;
        }else{
            std::swap(array[target],array[low2]);
            target++;
            low2++;
        }
        totalMovement ++;
    }
    if(low1<high1){
        for(unsigned int i=low1;i<high1;i++){
            std::swap(array[target],array[i]);
            target++;
            totalMovement ++;
        }
    }
    //   printArray();

}















