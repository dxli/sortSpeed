/**
  * Compare speed, complexity of sorting algorithms
  * merge sort
  * heap sort
 *
  * */
#include <iostream>
#include <vector>

#include"actionFactory.h"

int main() {
    actionFactory af(actionFactory::MergeSort);
    std::vector<actionFactory::SortType> aTypes={
        actionFactory::MergeSort,
        actionFactory::InPlaceMergeSort,
        actionFactory::HeapSort
    };
    for(auto it =aTypes.begin();it!=aTypes.end();it++){
        af.setType(*it);
        af.run();
    }

    return 0;



}
