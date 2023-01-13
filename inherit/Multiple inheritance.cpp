#include <iostream>
#include <string>

using namespace std;


class animal{
public:
    int age;
};

class sheep: public animal
{

};

class Camel:public animal
{

};

class Alpaca:public sheep , public Camel
{
    //对象在被创建的时候，会有两个age，而不是3个age；
    //即子类被创建的时候，会调用父类的构造函数，然后把属性都给子类
};

int main(){
    // sheep s1;
    // cout << sizeof(s1.age) << endl;
    Alpaca a1;
    cout << a1.sheep::age << endl;
    system("pause");
}