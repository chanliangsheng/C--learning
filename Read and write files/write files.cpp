#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main(){
    std::ofstream ofs;

    ofs.open("test.txt" , std::ios::out);

    ofs << "daxiongmei aiwo" << endl
    << "dfasdf" << endl
    << " faefasfsea" << endl;

    ofs.close();
}