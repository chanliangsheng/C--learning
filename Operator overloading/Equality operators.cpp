#include <iostream>
#include <string>

using namespace std;
//运算符重载也可以发生函数重载

//编译器会对类提供四个函数：析构函数，构造函数，赋值运算符函数，默认拷贝构造函数

//但是赋值运算符函数会是浅拷贝，意思就是把东西完整地拷贝过去，连指针也是完整地拷贝，而不是拷贝指针指向的地址
class person{
public:
    int *age;
    person(int age){
        this->age = new int(age);
    }

    ~person(){
        if (this->age != NULL )
        {
            delete(this->age);
        }//析构函数，如果age指针不为空，则释放
        
    }

    person& operator=(person &p){
        if (this->age != NULL)
        {
            delete this->age;
        }//如果本来的对象的age是在堆区有存放数据的，那么需要先释放，不然会到程序结束时才释放
        
        this->age = new int(*p.age);
        return *this;
    }//返回的需要是引用，不然又调用了拷贝构造函数赋值一份新的
};



void test(){
    person p1(10);
    person p2(20);

    p2 = p1;//在这里会调用类的赋值运算符函数，如果是浅拷贝的话，调用析构函数会重复释放同一块内存，所以在等式运算符函数中，需要深拷贝
    //本质上是p2.operator=(p1)，编译器优化成了p2 = p1
    cout << *p1.age << endl;
    cout << *p2.age << endl;
}


int main(){
    test();
    system("pause");
}