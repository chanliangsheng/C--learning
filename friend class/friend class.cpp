#include <iostream>
#include <string>
using namespace std;

//本质就是希望一些类外的东西可以访问类内的private属性，所以有友元类，全局函数友元，成员函数友元；都是不同场景下的使用

class Room{
    friend class goodGay;//goodGay作为友元可以让goodGay这个类访问Room的private属性
public:
    string livingroom;
private:
    string bedroom;
public:
    Room(){
        livingroom = "客厅";
        bedroom = "卧室";
    }//构造函数
};

class goodGay{
public:
    Room* buliding;
    goodGay(){
       buliding = new Room;
    }//构造函数为新建一个Room类，并且用buliding指向这个类

    void visit(){
        cout << "好基友正在访问" << buliding->bedroom;
        cout << "好基友正在访问" << buliding->livingroom;
    }
};

void test(){
    goodGay gg;
    gg.visit();
}

int main(){
    test();

    system("pause");
}