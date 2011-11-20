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
    default:
        std::cout<<"Unknown algorithm type, exit...\n";
        exit(0);
    }

    this->aType=aType;
}

void actionFactory::run(unsigned int repeat){
    heapSort hs0(1);
    statistics normalizedSpeed;
    statistics comparison;
    statistics movement;
    struct timeval t_start,t_end;

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












