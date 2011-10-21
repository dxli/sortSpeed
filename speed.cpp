#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<string>
#include<unistd.h>
#include<grace_np.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<boost/math/special_functions/ellint_2.hpp>
#include"rs_vector.h"
#include"randomInit.h"

using namespace std;
void angle2New(int& counts)
{
    RS_Vector vp(0.,0.);
    RS_Vector vp1,vp2;
    for(int i=0; i<counts; i++) {
        vp1.set(random()/(1.0+RAND_MAX),random()/(1.0+RAND_MAX));
        vp2.set(random()/(1.0+RAND_MAX),random()/(1.0+RAND_MAX));
        vp.angleBetweenNew(vp1,vp2);
    }
}
double timeDiff(timeval& t0, timeval& t1)
{
    return (t1.tv_sec - t0.tv_sec) + 1e-6*(t1.tv_usec - t0.tv_usec);
}

void angle2Old(int& counts)
{
    RS_Vector vp(0.,0.);
    RS_Vector vp1,vp2;
    for(int i=0; i<counts; i++) {
        vp1.set(random()/(1.0+RAND_MAX),random()/(1.0+RAND_MAX));
        vp2.set(random()/(1.0+RAND_MAX),random()/(1.0+RAND_MAX));
        vp.angleBetweenOld(vp1,vp2);
    }
}

void mirrorOld(int& counts)
{
    RS_Vector vp(0.,0.);
    RS_Vector vp1,vp2;
    RS_Vector vp3(vp);
    for(int i=0; i<counts; i++) {
        vp1.set(random()/(1.0+RAND_MAX),random()/(1.0+RAND_MAX));
        vp2.set(random()/(1.0+RAND_MAX),random()/(1.0+RAND_MAX));
        vp3.mirrorOld(vp1,vp2);
    }
}


void mirrorNew(int& counts)
{
    RS_Vector vp(0.,0.);
    RS_Vector vp1,vp2;
    RS_Vector vp3(vp);
    for(int i=0; i<counts; i++) {
        vp1.set(random()/(1.0+RAND_MAX),random()/(1.0+RAND_MAX));
        vp2.set(random()/(1.0+RAND_MAX),random()/(1.0+RAND_MAX));
        vp3.mirrorNew(vp1,vp2);
    }
}

void valueCompare(int counts)
{
    RS_Vector vp0,vp1,vp2;
    for(int i=0; i<counts; i++) {
        vp0.set(random()/(1.0+RAND_MAX),random()/(1.0+RAND_MAX));
        vp1.set(random()/(1.0+RAND_MAX),random()/(1.0+RAND_MAX));
        vp2.set(random()/(1.0+RAND_MAX),random()/(1.0+RAND_MAX));
        RS_Vector vp(vp0);
        std::cout<<"Old: "<<vp.mirrorOld(vp1,vp2)<<std::endl;
        vp=vp0;
        std::cout<<"New: "<<vp.mirrorNew(vp1,vp2)<<std::endl;
    }

}

void speedEI2(int counts)
{
    for(int i=0; i<counts; i++) {
boost::math::ellint_2<double,double>(random()/(1.0+RAND_MAX),random()/(1.0+RAND_MAX)*M_PI/2.);
    }
}
int main(int argc,char *argv[])
{
//init states
    char randomBuffer[257];
    randomInit(randomBuffer);
    double a;
    delete &a;

    //std::cout<<sizeof(double*)<<std::endl;
    RS_Vector vp0,vp1,vp2;
    struct timeval t_start,t_end;
    int counts=100000;
    gettimeofday(&t_start,NULL);
    speedEI2(counts);
    gettimeofday(&t_end,NULL);
    std::cout<<"Speed of incomplete Elliptic integral (2nd type)="<<counts/timeDiff(t_start,t_end)<<" /s\n";
    for(double x=0.;x<M_PI/2.;x+=0.01){
    std::cout<<x<<" "<<boost::math::ellint_2<double,double>(0.9,x)<<std::endl;
    }
    return 0;

    mirrorOld(counts);
    gettimeofday(&t_end,NULL);
    std::cout<<"Old speed = "<<counts/timeDiff(t_start,t_end)<<std::endl;
    gettimeofday(&t_start,NULL);
    mirrorNew(counts);
    gettimeofday(&t_end,NULL);
    std::cout<<"New speed = "<<counts/timeDiff(t_start,t_end)<<std::endl;

    return 0;
}
