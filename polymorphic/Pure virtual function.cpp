#include <iostream>
#include <string>

using namespace std;
//目的是提供一个抽象类，可以使用多态；提供一个方法，对不同的类进行不同的处理

class drink{
public:
    virtual void boil() = 0;//加热
    virtual void addwater() = 0;//加水
    virtual void addsomething() = 0;//加东西

    void make(){
        boil();
        addwater();
        addsomething();
        cout << "done!" << endl;
    }//制作饮料的步骤，同时会被子类所继承
};

class tea:public drink
{
    void boil(){
        cout << "正在烧开" << endl;
    }
    void addwater(){
        cout << "正在加水" << endl;
    }
    void addsomething(){
        cout << "正在加茶叶" << endl;
    }
};

class coffee:public drink
{
    void boil(){
        cout << "正在烧开" << endl;
    }
    void addwater(){
        cout << "正在加水" << endl;
    }
    void addsomething(){
        cout << "正在加咖啡豆" << endl;
    }
};

void make(drink *drink){
    drink->make();
    delete drink;
}//这里是精髓，父类的指针来接收子类对象；这样可以对不同的子类，来进行不一样的操作，还可以统一回收内存
//
//
//
//
//
//

int main(){
    // tea t1;//如果tea里面没有改变boil等等的纯虚函数，这样是不合法的，因为这样会认为tea是抽象类
    make(new coffee);
    system("pause");
}