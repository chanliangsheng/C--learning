#include <iostream>
using namespace std;

class person{
public:
  person(const person &p){
    cout << "拷贝构造函数" << endl;
    m_age = p.m_age;
  }//拷贝构造函数

  person(int age){
    m_age = age;
    cout << "有参构造函数" << endl;
  }//有参构造函数
  int m_age;
};

person  test1(person p){
  cout << p.m_age << endl;
  p.m_age = 10;
  return p;
}

int main(){
    person p1(10);

    person result = test1(p1);

    cout << result.m_age;

    system("pause");
}