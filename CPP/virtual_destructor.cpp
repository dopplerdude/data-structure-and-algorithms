#include <iostream>

class A
{
    public:
    A() { std::cout << "A()" << std::endl;}

    virtual ~A() { std::cout << "~A()" << std::endl;}
};

class B : public A
{
    public:
    B() { std::cout << "B()" << std::endl;}

    virtual ~B() { std::cout << "~B()" << std::endl;}
};

int main()
{
    A* a= new A;
    A* b = new B;
    B c;
    delete a;
    delete b;

    return(0);
}