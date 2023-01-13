#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;



int main(){
    auto start = std::chrono::high_resolution_clock::now();
    ifstream ifs;//创造输入流对象

    string file_name = "D://R package//data//test.mzML";

    ifs.open(file_name);//打开r文件

    if (!ifs.is_open())
    {
        cout << "fail for open this file";
    }
    
    string buf;

    while (getline(ifs , buf))
    {
        
    }//不断地读取到buf中，然后打印
    
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds >(stop - start);

    std::cout << "Time taken by function: "
              << duration.count() << " seconds " << std::endl;
    system("pause");
}