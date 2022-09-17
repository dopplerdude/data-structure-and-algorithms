#include <iostream>

void swap(int*, int*);

int main(int argc, char** argv)
{
    std::cout << "Hello World!!" << std::endl;
    if(argc != 3)
        return(0);
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    std::cout << "Lets swap :   " << "a:" << a << " and " << "b:" << b << "\n";
    swap(&a, &b);
    std::cout << "After swap:   " << "a:" << a << " and " << "b:" << b << "\n";
    return(0);
}
