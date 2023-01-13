#include <iostream>
#include <string>

using namespace std;
//运算符重载也可以发生函数重载

class person{
public:
    int A;
    int B;
    person(int A , int B){
        this->A = A;
        this->B = B;
    }//有参构造函数
    person(){
        this->A = 10;
        this->B = 10;
    }//默认构造函数
};


person operator+(person &p1 , person &p2){
    person p3;
    p3.A = p1.A + p2.A;
    p3.B = p1.B + p2.B;
    return p3;
}//运算符重载+


int main(){
    person p1;
    person p2(20 , 20);
    person p3 = p1 + p2;
    cout << p1.A << endl;
    cout << p2.A << endl;
    cout << p3.A << endl;
    system("pause");
}