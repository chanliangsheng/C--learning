#include <iostream>
#include <string>

using namespace std;
//虚析构解决的是父类指针指向子类的时候，没有走子类的析构函数的问题
//目的是提供一个抽象类，可以使用多态；提供一个方法，对不同的类进行不同的处理

class drink{
public:
    virtual void boil() = 0;//加热
    virtual void addwater() = 0;//加水
    virtual void addsomething() = 0;//加东西
    drink(){
        cout << "drink的构造函数" <<endl;
    }
    void make(){
        boil();
        addwater();
        addsomething();
        cout << "done!" << endl;
    }//制作饮料的步骤，同时会被子类所继承

    virtual ~drink(){
        cout << "drink的析构函数" << endl;
    }
    // ~drink(){
    //     cout << "drink的析构函数" << endl;
    // }
    // 无虚析构函数的析构函数
};

class tea:public drink
{
public:
    tea(){
        cout << "tea的构造函数" <<endl;
    }
    void boil(){
        cout << "正在烧开" << endl;
    }
    void addwater(){
        cout << "正在加水" << endl;
    }
    void addsomething(){
        cout << "正在加茶叶" << endl;
    }
    ~tea(){
        cout << "tea的析构函数" <<endl;
    }
};

class coffee:public drink
{public:
    coffee(){
        cout << "coffee的构造函数" <<endl;
    }
    void boil(){
        cout << "正在烧开" << endl;
    }
    void addwater(){
        cout << "正在加水" << endl;
    }
    void addsomething(){
        cout << "正在加咖啡豆" << endl;
    }
    ~coffee(){
        cout << "coffee的析构函数" <<endl;
    }
};

void make(drink *drink){
    drink->make();
    delete drink;
}//这里是精髓，父类的指针来接收子类对象；这样可以对不同的子类，来进行不一样的操作，还可以统一回收内存
//
//
//如果父类drink的析构函数不是虚析构，那么释放内存的时候是执行了父类的析构函数，而没有执行子类的析构函数,delete drink执行的是父类的内存释放，而子类的内存并没有被释放；
//这是因为如果不是虚析构，那么就像不是虚函数一样，析构函数的地址在编译的时候就已经绑定了，如果加上虚函数作为虚析构函数，那么就会运行的时候再进行地址的选择
//
//

int main(){
    // tea t1;//如果tea里面没有改变boil等等的纯虚函数，这样是不合法的，因为这样会认为tea是抽象类
    make(new coffee);
    system("pause");
}