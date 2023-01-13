#include <iostream>
#include <string>
using namespace std;

//目的：使得cout可以输出自定义的类型

class person{
public:
    int age;
    string phone;
    person(){
        age = 10;
        phone = "13213";
    }
};

void operator<<(ostream &cout , person &p){//cout需要传递引用，因为流对象是花销很多的，如果传递副本会过大开销，所以只允许传递引用
    cout << p.age << endl << p.phone << endl;
}

int main(){
    person p1;
    cout << p1;
    system("pause");
}