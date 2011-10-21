#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<sys/types.h>
#include<sys/time.h>
#include<cmath>
#include"randomInit.h"

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

    void createBoxOld(number_t, number_t,number_t,number_t,number_t);
    void createBoxNew(number_t, number_t,number_t,number_t,number_t);

};
void runRotateNew(int& counts);
void runRotateOld(int& counts);
void rotateOld(Matrix* th, number_t angle);
void rotateNew(Matrix* th, number_t angle);
void runRotateNew(int& counts)
{
    Matrix m;
    double a;
    for(int i=0; i<counts; i++) {
        a= random()*(2.*M_PI/(1.0+RAND_MAX));
        rotateNew(&m,a);
    }
}

void runRotateOld(int& counts)
{
    Matrix m;
    double a;
    for(int i=0; i<counts; i++) {
        a= random()*(2.*M_PI/(1.0+RAND_MAX));
        rotateOld(&m,a);
    }
}
double runCreateBoxNew(int& counts ){
    Matrix m;
    double a,b,c,d,e;
    timeval t_start,t_end;
    gettimeofday(&t_start,NULL);
    for(int i=0; i<counts; i++) {
        a= random()*(2.*M_PI/(1.0+RAND_MAX));
        b= random()*(2.*M_PI/(1.0+RAND_MAX));
        c= random()*(2.*M_PI/(1.0+RAND_MAX));
        d= random()*(2.*M_PI/(1.0+RAND_MAX));
        e= random()*(2.*M_PI/(1.0+RAND_MAX));
        m.createBoxNew(a,b,c,d,e);
    }
    gettimeofday(&t_end,NULL);
    return counts/(t_end - t_start);
}
double runCreateBoxOld(int& counts ){
    Matrix m;
    double a,b,c,d,e;
    timeval t_start,t_end;
    gettimeofday(&t_start,NULL);
    for(int i=0; i<counts; i++) {
        a= random()*(2.*M_PI/(1.0+RAND_MAX));
        b= random()*(2.*M_PI/(1.0+RAND_MAX));
        c= random()*(2.*M_PI/(1.0+RAND_MAX));
        d= random()*(2.*M_PI/(1.0+RAND_MAX));
        e= random()*(2.*M_PI/(1.0+RAND_MAX));
        m.createBoxOld(a,b,c,d,e);
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

//void rotateNew(Matrix *th,number_t angle)
//{
//        number_t ta;

//        ta = th->a * cos(angle) + th->c * sin(angle);
//        th->c = th->c * cos(angle) - th->a * sin(angle);
//        th->a = ta;
//        ta = th->b * cos(angle) + th->d * sin(angle);
//        th->d = th->d * cos(angle) - th->b * sin(angle);
//        th->b = ta;

//}



void Matrix::createBoxOld(number_t scaleX, number_t scaleY, number_t angle, number_t x, number_t y) {
        a = scaleX * cos(angle);
        b = scaleX * sin(angle);
        c = -scaleY * sin(angle);
        d = scaleY * cos(angle);
        tx = x * cos(angle) - y * sin(angle);
        ty = x * sin(angle) + y * cos(angle);
}
void Matrix::createBoxNew(number_t scaleX, number_t scaleY, number_t angle, number_t x, number_t y) {
    number_t ca(cos(angle));
    number_t sa(sin(angle));
        a = scaleX * ca;
        b = scaleX * sa;
        c = -scaleY * sa;
        d = scaleY * ca;
        tx = x * ca - y * sa;
        ty = x * sa + y * ca;
}
int main(int argc,char *argv[])
{
//init states
    char randomBuffer[257];
    randomInit(randomBuffer);

    struct timeval t_start,t_end;
    int counts=10000000;
    gettimeofday(&t_start,NULL);
   runRotateOld(counts);
    gettimeofday(&t_end,NULL);
double speed0(counts/(t_end-t_start));
    std::cout<<"Old rotation speed = "<<speed0<<std::endl;
    gettimeofday(&t_start,NULL);
   runRotateNew(counts);
    gettimeofday(&t_end,NULL);
double speed1(counts/(t_end-t_start));
    std::cout<<"New rotation speed = "<<speed1<<std::endl;
    std::cout<<"New rotation speed difference= "<<speed1/speed0<<std::endl;
    speed0=runCreateBoxOld(counts);
    std::cout<<"Old createBox speed = "<<speed0<<std::endl;
    speed1=runCreateBoxNew(counts);
    std::cout<<"New createBox speed = "<<speed1<<std::endl;
    std::cout<<"New createBox speed difference= "<<speed1/speed0<<std::endl;

    return 0;
}
