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

using namespace std;

class A {
private:
static int i;
public:
A(){
cout<<"A::constructor\n";
}
A(int j){
cout<<"A::constructor(int)\n";
i=j;
};

~A(){
cout<<"A::deconstructor\n";
//delete this;
//cout<<"A::deconstructor undefined\n";
}
int geti(){
return i;
}
};
int A::i;
int main()
{
//A* pnew A;
//delete pa;
A a0(0);
A a1;

std::cout<<a1.geti()<<"\n";
//delete &a;
return 0;
}
