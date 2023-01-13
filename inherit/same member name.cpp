#include <iostream>
#include <string>

using namespace std;

class father{
public:
    int a;
    father(int a){
        this->a = a;
        b = 1;
        c = 1;
    }
protected:
    int b;
private:
    int c;
};

class son:protected father{
public:
    int a;
    son(int a):father(2)
    {

    }//因为子类在被创建的时候，需要先创建父类，所以需要调用父类的构造函数，所以需要显式地构造一个父类
    void test(){
        cout << this->father::a << endl;
    }
};//如果有同名对象，那么a就会访问本类的a；如果想访问父类的a，需要加上作用域


int main(){
    son s1(1);
    s1.test();
    system("pause");
}