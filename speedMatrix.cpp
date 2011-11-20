#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<sys/types.h>
#include<sys/time.h>
#include<cmath>
//#include"randomInit.h"

using namespace std;
typedef double number_t;
double operator - ( const timeval& t0, const timeval& t1) {
    return (t0.tv_sec - t1.tv_sec) + 1e-6*(t0.tv_usec - t1.tv_usec);
}

class Matrix {
public:
    Matrix(){
        reset();
    }
    number_t a,b,c,d,tx,ty;
    void reset(){
        a=random()/(1.0+RAND_MAX);
        b=random()/(1.0+RAND_MAX);
        c=random()/(1.0+RAND_MAX);
        d=random()/(1.0+RAND_MAX);
        tx=random()/(1.0+RAND_MAX);
        ty=random()/(1.0+RAND_MAX);
    }
};

double runRotateNew(int& counts);
double runRotateOld(int& counts);
void rotateOld(Matrix* th, number_t angle);
void rotateNew(Matrix* th, number_t angle);
double runRotateNew(int& counts)
{
    Matrix m;
    double a;
    timeval t_start,t_end;
    gettimeofday(&t_start,NULL);
    for(int i=0; i<counts; i++) {
        a= random()*(2.*M_PI/(1.0+RAND_MAX));
        rotateNew(&m,a);
    }
    gettimeofday(&t_end,NULL);
    return counts/(t_end - t_start);
}

double runRotateOld(int& counts)
{
    Matrix m;
    double a;
    timeval t_start,t_end;
    gettimeofday(&t_start,NULL);
    for(int i=0; i<counts; i++) {
        a= random()*(2.*M_PI/(1.0+RAND_MAX));
        rotateOld(&m,a);
    }
    gettimeofday(&t_end,NULL);
    return counts/(t_end - t_start);
}

void rotateOld(Matrix *th,number_t angle)
{
    number_t ta, tb, tc, td;

    ta = th->a * cos(angle) + th->c * sin(angle);
    tb = th->b * cos(angle) + th->d * sin(angle);
    tc = th->c * cos(angle) - th->a * sin(angle);
    td = th->d * cos(angle) - th->b * sin(angle);

    th->a = ta;
    th->b = tb;
    th->c = tc;
    th->d = td;

}

void rotateNew(Matrix *th,number_t angle)
{
    number_t ta;
    double ca(cos(angle));
    double sa(sin(angle));

    ta = th->a * ca + th->c * sa;
    th->c = th->c * ca - th->a * sa;
    th->a = ta;
    ta = th->b * ca + th->d * sa;
    th->d = th->d * ca - th->b * sa;
    th->b = ta;

}

int main(int argc,char *argv[])
{
    //init states
    //    char randomBuffer[257];
    //    randomInit(randomBuffer);

    int counts=200000000;
    double speed0( runRotateOld(counts));
    std::cout<<"Old rotation speed = "<<speed0<<std::endl;
    double speed1( runRotateNew(counts));
    std::cout<<"New rotation speed = "<<speed1<<std::endl;
    std::cout<<"Relative speed = "<<speed1/speed0<<std::endl;
    return 0;
}
