#include <iostream>
#include "par.h"

extern int ii;
int main()
{
    std::cout<<ii<<std::endl;

    int i=42;
    int &r1=i;
    const int &r2=i;
    std::cout<<i<<","<<r1<<","<<r2<<std::endl;

    r1=0;
    std::cout<<i<<","<<r1<<","<<r2<<std::endl;

    double j=42.66;
    const int &r3=j;
    //const int &r2=i;
    std::cout<<j<<","<<r3<<","<<std::endl;

    j=44.66;
    std::cout<<j<<","<<r3<<","<<std::endl;    
}