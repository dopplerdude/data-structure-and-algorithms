#include <iostream>

class A
{
    public:
    void x()    { std::cout<< "A::x()" << std::endl;}
    void y()    { std::cout<< "A::y()" << std::endl;}
    virtual void z()    { std::cout<< "A::z()" << std::endl;}
};

class B : public A
{
    public:
    void x()    { std::cout<< "B::x()" << std::endl;}
    virtual void y()    { std::cout<< "B::y()" << std::endl;}
    virtual void z()    { std::cout<< "B::z()" << std::endl;}
};

class C : public B
{
    public:
    void x()    { std::cout<< "C::x()" << std::endl;}
    virtual void y()    { std::cout<< "C::y()" << std::endl;}
    virtual void z()    { std::cout<< "C::z()" << std::endl;}
};

int main()
{
    B* b = new C;
    A* a = b;

    a->x(); //  A::x()
    a->y(); //  A::y()
    a->z(); //  c::z()

    b->x(); //  B::x()
    b->y(); //  C::y()
    b->z(); //  C::z()
    
    return(0);
}
