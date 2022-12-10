#include <iostream>

#include <string>


class Sales_data
{
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
public:
    // 非委托
    Sales_data(std::string s, unsigned cnt, double price):
            bookNo(s), units_sold(cnt), revenue(cnt*price){}
    // 其余构造函数全都委托给另一个构造函数
    Sales_data(): Sales_data("",0,0){}
    Sales_data(std::string s):Sales_data(s,0,0) {}
    //Sales_data(std::istream &is) : Sales_data()
    //    { read(is,*this);}

    std::string isbn() const {return bookNo;}
    int sold() {return units_sold;}
};



int main()
{
    Sales_data sd1("n1",50,66);
    std::cout<<sd1.isbn()<<std::endl;
    const Sales_data sd2("n2",60,77);
    std::cout<<sd2.isbn();

    sd1.sold();
    //error
    //sd2.sold();

}
