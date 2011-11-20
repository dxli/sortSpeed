/**
 * heap sorting
 * */
#include <iostream>
#include <string>
#include<fstream>
#include<string>
#include<vector>
#include<time.h>
#include<sys/time.h>
#include"randomInit.h"

int main() {
    std::string sr("/dev/urandom");
    struct timeval t_start;
    gettimeofday(&t_start,NULL);
    std::ifstream in1(sr.c_str());
    char random_buf[257];
    if (! in1.is_open())
    {
        std::cerr<<"Can not open" <<sr<<std::endl;
        srandom(t_start.tv_usec);
    }
    else
    {
        in1.read(random_buf,256*sizeof(char));
        in1.close();
        initstate(t_start.tv_usec,random_buf,256);
        setstate(random_buf);
    }
    std::vector<unsigned int> array(100);
    for(auto it=array.begin(); it != array.end(); it++) {
        *it = (unsigned int) (double(100.)*random()/(double(1.0)+RAND_MAX));
    }
    //form a binary tree
    unsigned int length=array.size() -1;
    unsigned int high=length;
    //the binary tree, 
    //          low = (high - 1) >> 1;
    //          high= (low<<1) +1;
    unsigned int low=(length -1 )>>1;
    while(length>0) {
        if ( high ) {//still forming the binary tree
            if(array[low] < array[high]) {
                std::swap(array[low],array[high]);
            } else {
                if(high & 0x1)  low--;
                high--;
                continue;
            }
        } else {//sorting phase, picking the largest element from the first place
            std::swap(array[0],array[length]);
            length--;
        }

        //maintain the binary tree order from the changed position (high)
        unsigned int i1=high;
        unsigned int k= (i1<<1)+1;
        while(k<=length) {
            if(k+1<=length) {
                if(array[k]<array[k+1]) k++;
            }
            if(array[i1]<array[k]) {
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
    for(auto it=array.begin(); it != array.end(); it++) {
        std::cout<<" "<<*it;
    }
    std::cout<<std::endl;
    return 0;



}
