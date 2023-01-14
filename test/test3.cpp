// CPP program to illustrate
// Boost.Lexical_Cast in C++
#include "boost/lexical_cast.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <charconv>


using namespace boost;



void test1(std::string &s , int time){
    for (int i = 0; i < time; i++)
    {
    //    double a = ::atof(s.c_str());
        double a = boost::lexical_cast<double>(s);
       
    }
    
}

void test2(std::string &s , int time){
    for (int i = 0; i < time; i++)
    {
       double a = std::stod(s);
    }
}
int main() {

std::string s1 = "123124124124";

    auto start = std::chrono::high_resolution_clock::now();

    test1(s1 , 1000000);

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds >(stop - start);

    std::cout << "Time taken by function: "
              << duration.count() << " seconds " << std::endl;







system("pause");
return 0;
}
