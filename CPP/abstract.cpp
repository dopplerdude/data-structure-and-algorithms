/*
*   Abstract base class 
*   A class containing at least one Pure Virtual Function is called an 
*   Abstract Base Class
*
*/

#include <iostream>

class Shapes    //Abstract Base Class - can not be instantiated
{
  public:
  // Pure virtual function can be defined, but still
  // class' objects can not be instantiated, it still is
  // Abstract class
  virtual void draw() = 0;  // Pure virtual function

};

class Polygon: public Shapes
{
  public:
  void draw() { std::cout << "draw -> Polygon" << std::endl;}
};

class ClosedConics: public Shapes
{
  public:
  void draw() { std::cout << "Init ClosedConics" << std::endl;}
};

class Triangle: public Polygon
{
  public:
  void draw() { std::cout << "draw -> Triangle" << std::endl;}
};

class Quadrilateral: public Polygon
{
  public:
  void draw() { std::cout << "draw -> Quadrilateral" << std::endl;}
};

class Circle: public ClosedConics
{
  public:
  void draw() {
    ClosedConics::draw();   
    std::cout << "draw -> Circle" << std::endl;
    }
};

class Ellipse: public ClosedConics
{
  public:
  void draw() {
    ClosedConics::draw();   
    std::cout << "draw -> Ellipse" << std::endl;
    }
};

int main()
{
    Shapes* arr[] = { new Ellipse, new Circle, new Quadrilateral, new Triangle};
    for(int index = 0; index < sizeof(arr) / (sizeof(arr[0])); index++)
    {
        arr[index]->draw();   
    }

    return(0);
}