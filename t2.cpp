#include <iostream>
#include <string>
class Animal {
        public:
    virtual std::string talk()=0;
};
 
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
    write(Cat());
    write(Dog());
} 
