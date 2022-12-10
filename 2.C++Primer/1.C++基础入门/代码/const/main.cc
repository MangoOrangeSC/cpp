#include <iostream>


int main()
{
    double j=42.66;
    const int &r3=j;
    //const int &r2=i;
    std::cout<<j<<","<<r3<<","<<std::endl; //42.66 42

    j=44.66;
    std::cout<<j<<","<<r3<<","<<std::endl; //44.66 42    

    double i = 10.3;
    const double &i_ = i;
    std::cout<<i<<","<<i_<<","<<std::endl;  //10.3,10.3,   

    i = 12.3;
    std::cout<<i<<","<<i_<<","<<std::endl;  //12.3,12.3   

    // 顶层const不影响指针指向
    int m = 5;
    int * const i = &m; 
}
