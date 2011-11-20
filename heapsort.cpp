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
    for(auto it=array.begin();it != array.end();it++){
            *it = (unsigned int) (double(100.)*random()/(double(1.0)+RAND_MAX));
    }
    //form a binary tree
    unsigned int j=(array.size() -1 )>>1;
    for(unsigned int i=array.size() -1;i>0;i--){
            //std::cout<<"i="<<i<<std::endl;
            if( array[j] < array[i]) {
                    std::swap(array[i],array[j]);
                    unsigned int i1=i,k= (i<<1)+1;
                    while(k<array.size()){
                            if(k+1<array.size()) {
                                    if(array[k]<array[k+1]) k++;
                            }
                            if(array[i1]<array[k]) {
                                    std::swap(array[i1],array[k]);
                                    i1=k;
                                    k= (k<<1)+1;
                            }else break;
                    }
            }
            if( i & 0x1) j--;
    }
     
    for(unsigned int i=0;i<array.size();i++){
            std::cout<<"i= "<<i<< " array["<<i<<"]="<<array[i];
            
            int k=(i<<1)+1;
            if( k<array.size()) std::cout<<' '<<(array[i]>=array[k]);
            k++;
            if( k<array.size()) std::cout<<' '<<(array[i]>=array[k]);
            std::cout<<std::endl;
    }
    std::cout<<std::endl;

    //sorting
    j=array.size() -1;
    while(j>0){
            std::swap(array[0],array[j]);
            j--;
            unsigned int i=0, k=1;
            while(k<j){
                    if( k+1 <= j) {
                            if( array[k] < array[k+1]) k++;
                    }
                    if( array[i]<array[k]){
                            std::swap(array[i],array[k]);
                    i=k;
                    k=(k<<1)+1;
                    }else break;
            }

    }
    
    for(auto it=array.begin();it != array.end();it++){
            std::cout<<" "<<*it;
    }
    std::cout<<std::endl;
    
    
        
} 
