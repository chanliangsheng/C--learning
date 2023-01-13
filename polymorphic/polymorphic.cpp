#include <iostream>
#include <string>

using namespace std;

class animal{
public:
    // void speak(){
    //     cout << "动物在说话";
    // }
    virtual void speak(){
        cout << "动物在说话";
    }
};

class cat:public animal
{
    void speak(){
        cout << "猫在说话";
    }

    void speak2(){
        cout << "猫2在说话";
    }
};

class dog:public animal
{
    void speak(){
        cout << "狗在说话";
    }
};

void speak_(animal &animal){
    animal.speak();
    // animal.speak2();
    // 编译过不了，因为这里的是animal类，在运行期的时候才把animal对象强制转化为cat对象
}

int main(){
    cat c1;
    speak_(c1);//当传入对象为猫的时候，还是执行了动物类中的speak函数;这是因为speak_函数在编译器就把animal.speak()函数的地址绑定了,无论传入的是什么对象，都执行animal的speak函数；
    //如果不想让speak的地址先绑定，而是按照我们传入的对象，再确定函数地址，那么需要把animal的speak函数该为虚函数
    system("pause");
}