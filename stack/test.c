#include "itoa.h"

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        printf("#of Arguments provided:%d, required #of arguments are:3\n arg_1:executable name\narg_2:number to be converted to string\narg_3:base\n", argc);
        return(0);
    }
    char buffer[20];
    printf("itoa of %d is %s\n", atoi(argv[1]), itoa(atoi(argv[1]), buffer, atoi(argv[2])));
    return(0);
}

