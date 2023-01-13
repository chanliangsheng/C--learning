#include <iostream>
#include <string>
using namespace std;

class phone{
public:
    phone(){
        phone_name = "test";
    }//默认构造函数

    phone(string phone_name):phone_name(phone_name)
    {
        cout << "phone的有参构造函数调用" << endl;
    }//有参构造函数进行初始化

    ~phone(){
        cout << "phone的析构函数调用" << endl;
    }
     string phone_name;
};

class person{
public:
    string m_name;
    phone p1;
    person(string name , string phone_name)
    {//这样会先进行phone的默认函数构造，如果用初始化列表的方式来构造的话，会调用phone的有参构造函数
        p1.phone_name = phone_name;
        m_name = name;
        cout << "person的构造函数调用" << endl;
    }
    ~person(){
        cout << "person的析构函数的调用" << endl;
    }
};

void test(string name = "陈亮生" , string phone_name = "15919330529"){
    person chan(name , phone_name);
}


int main(){
    test();
    system("pause");
}