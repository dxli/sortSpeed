#include <iostream>
#include <vector>
#include <future>
#include <boost/thread.hpp>


class piPartial {
        public:
        piPartial(int c);
        std::vector<double> pret;
        void operator() ( int i ){
                partial_pi(i);
        }
        private:
        void partial_pi(int i);
        int index,copies;
        double ret;
};
piPartial::piPartial(int c) :ret(0.){
        if( c>=1){
                copies=c;
                pret.resize(c);
        }
}

void piPartial::partial_pi(int index){
        if(index<=0 || index > copies) return;
        double a=0.;
        int imax=( (100000*copies+index)<<2) -3;
        int di=copies<<2;
        int imin=(index<<2) - 3;
        for(int i0=imin;i0<=imax;i0+=di){
                a += 2./(double(i0)*double(i0+2));
        }
        std::cout<<"copy: "<<index<<" sum="<<a<<std::endl;
        pret.at(index-1)=a;
        return;
}

int main()
{
        int copies=6;
        piPartial p(copies);
        std::vector< boost::thread> ths;

        for(int i=1;i<=copies;i++){
            //std::future<double> answer=std::async(partial_pi(i,6));
            ths.push_back(  boost::thread(boost::ref(p),i));
        }
        for(auto it=ths.begin();it != ths.end();it++){
            //std::future<double> answer=std::async(partial_pi(i,6));
            it->join();
        }
        double ret=0.;
        for(int i=0;i<copies;i++){
        ret += p.pret.at(i);
        }
        std::cout<<"pi="<<4.*ret<<std::endl;
return 0;
    }
