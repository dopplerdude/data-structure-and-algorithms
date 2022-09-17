#include<stdio.h>

int n = 0x1a2b3c4d;

struct A
{
    char a;
    int b;
    short c;
    char d;
};


int main()
{
    for(int i = 0; i < sizeof(int); i++)
    {
        printf("Address = %llu, contents = %x\n", (unsigned long long)((char*)&n + i), *((unsigned char*)((char*)&n + i)) );
    }
    printf("hhn = %hhx\n", n);
 
    printf("off_a:%llu, off_b:%llu, off_c:%llu, off_d:%llu\n", 
    &((struct A*)0)->a, &((struct A*)0)->b, &((struct A*)0)->c, &((struct A*)0)->d);

    return(0);
}