#include <iostream>
using namespace std;

class person{
public:
  person(const person &p){
    cout << "�������캯��" << endl;
    m_age = p.m_age;
  }//�������캯��

  person(int age){
    m_age = age;
    cout << "�вι��캯��" << endl;
  }//�вι��캯��
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