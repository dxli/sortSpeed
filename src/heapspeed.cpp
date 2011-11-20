/**
  * Compare speed, complexity of sorting algorithms
  * merge sort
  * heap sort
 *
  * */
#include <iostream>
#include <cmath>
#include<time.h>
#include<sys/time.h>
#include"heapsort.h"
#include"timediff.h"

int main() {
        heapSort hs1(5);
        hs1.printArray();
        hs1.doMergeInPlaceSort();
        hs1.printArray();
        return 0;
    struct timeval t_start,t_end;
    const unsigned int imin=(1<<20);
    const unsigned int imax=(1<<27);
    std::cout<<"standard merge sort\n";
    for(unsigned int i=imin;i<imax;i <<= 1){

        heapSort hs0(i);
        gettimeofday(&t_start,NULL);
        hs0.doMergeSort();
        gettimeofday(&t_end,NULL);
        hs0.print();
        double t= ( t_end - t_start);
        std::cout<<"speed= "<<i/t<<" normalized speed="<<i*log2(double(i))/t<<std::endl;
    }
    std::cout<<"\nstandard heap sort\n";
    for(unsigned int i=imin;i<imax;i <<= 1){

        heapSort hs0(i);
        gettimeofday(&t_start,NULL);
        hs0.doHeapSort();
        gettimeofday(&t_end,NULL);
        hs0.print();
        double t= ( t_end - t_start);
        std::cout<<"speed= "<<i/t<<" normalized speed="<<i*log2(double(i))/t<<std::endl;
    }

    return 0;



}
