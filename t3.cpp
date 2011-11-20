#include <iostream>
#include <string>
class Animal {
        public:
                Animal(){
                        record=0x10101;
                }
    virtual std::string talk()=0;
    virtual int intxor(const int& i);
        private:
    int record;
};

int Animal::intxor(const int& i){
        int ret=i;
        ret ^= record;
        return ret;

}
class Cat : public Animal {
    std::string talk() { return std::string("Meow!"); }
};
 
class Dog : public Animal {
    std::string talk() { return std::string("Woof!"); }
};
 
static void write(Animal& a) {
        std::cout<<a.talk()<<std::endl;
}

 
int main() {
        int&& i=Cat().intxor(15);
        std::cout<<"i="<<i<<std::endl;
        i *= i;
        std::cout<<"i="<<i<<std::endl;
} 
