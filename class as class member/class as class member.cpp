#include <iostream>
#include <string>
using namespace std;

class phone{
public:
    phone(){
        phone_name = "test";
    }//Ĭ�Ϲ��캯��

    phone(string phone_name):phone_name(phone_name)
    {
        cout << "phone���вι��캯������" << endl;
    }//�вι��캯�����г�ʼ��

    ~phone(){
        cout << "phone��������������" << endl;
    }
     string phone_name;
};

class person{
public:
    string m_name;
    phone p1;
    person(string name , string phone_name)
    {//�������Ƚ���phone��Ĭ�Ϻ������죬����ó�ʼ���б�ķ�ʽ������Ļ��������phone���вι��캯��
        p1.phone_name = phone_name;
        m_name = name;
        cout << "person�Ĺ��캯������" << endl;
    }
    ~person(){
        cout << "person�����������ĵ���" << endl;
    }
};

void test(string name = "������" , string phone_name = "15919330529"){
    person chan(name , phone_name);
}


int main(){
    test();
    system("pause");
}