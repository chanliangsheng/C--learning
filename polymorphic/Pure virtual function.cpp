#include <iostream>
#include <string>

using namespace std;
//Ŀ�����ṩһ�������࣬����ʹ�ö�̬���ṩһ���������Բ�ͬ������в�ͬ�Ĵ���

class drink{
public:
    virtual void boil() = 0;//����
    virtual void addwater() = 0;//��ˮ
    virtual void addsomething() = 0;//�Ӷ���

    void make(){
        boil();
        addwater();
        addsomething();
        cout << "done!" << endl;
    }//�������ϵĲ��裬ͬʱ�ᱻ�������̳�
};

class tea:public drink
{
    void boil(){
        cout << "�����տ�" << endl;
    }
    void addwater(){
        cout << "���ڼ�ˮ" << endl;
    }
    void addsomething(){
        cout << "���ڼӲ�Ҷ" << endl;
    }
};

class coffee:public drink
{
    void boil(){
        cout << "�����տ�" << endl;
    }
    void addwater(){
        cout << "���ڼ�ˮ" << endl;
    }
    void addsomething(){
        cout << "���ڼӿ��ȶ�" << endl;
    }
};

void make(drink *drink){
    drink->make();
    delete drink;
}//�����Ǿ��裬�����ָ����������������������ԶԲ�ͬ�����࣬�����в�һ���Ĳ�����������ͳһ�����ڴ�
//
//
//
//
//
//

int main(){
    // tea t1;//���tea����û�иı�boil�ȵȵĴ��麯���������ǲ��Ϸ��ģ���Ϊ��������Ϊtea�ǳ�����
    make(new coffee);
    system("pause");
}