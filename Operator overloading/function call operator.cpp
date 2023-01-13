#include <iostream>
#include <string>

using namespace std;

class person{
public:
    int age;
    string name;
    person(){
        age = 10;
        name = "fds";
    }//默认构造函数
    
    void operator()(string text){
        cout << text;
    }//可以用对象使用某个函数那样使用
};



void test(){
    person p1;
    person p2;
    
    p1("test");
}

int main(){
    test();
    system("pause");
}