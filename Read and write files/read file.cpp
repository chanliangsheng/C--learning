#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main(){
    ifstream ifs;//输入流对象

    ifs.open("test.txt" , ios::in);//以读入的方式来打开文件

    string buf;

    while (getline(ifs , buf))
    {
        cout << buf << endl;
    }
    
    ifs.close();

    system("pause");
}