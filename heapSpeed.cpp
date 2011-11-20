/**
  * heap sorting
  * */
#include <iostream>
#include <cmath>
#include<time.h>
#include<sys/time.h>
#include"heapsort.h"
#include"timediff.h"

int main() {
    struct timeval t_start,t_end;
    for(unsigned int i=1000000;i<100000000;i *= 10){

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
