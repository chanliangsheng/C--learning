#include <iostream>
#include <string>

using namespace std;
//������������Ǹ���ָ��ָ�������ʱ��û�����������������������
//Ŀ�����ṩһ�������࣬����ʹ�ö�̬���ṩһ���������Բ�ͬ������в�ͬ�Ĵ���

class drink{
public:
    virtual void boil() = 0;//����
    virtual void addwater() = 0;//��ˮ
    virtual void addsomething() = 0;//�Ӷ���
    drink(){
        cout << "drink�Ĺ��캯��" <<endl;
    }
    void make(){
        boil();
        addwater();
        addsomething();
        cout << "done!" << endl;
    }//�������ϵĲ��裬ͬʱ�ᱻ�������̳�

    virtual ~drink(){
        cout << "drink����������" << endl;
    }
    // ~drink(){
    //     cout << "drink����������" << endl;
    // }
    // ����������������������
};

class tea:public drink
{
public:
    tea(){
        cout << "tea�Ĺ��캯��" <<endl;
    }
    void boil(){
        cout << "�����տ�" << endl;
    }
    void addwater(){
        cout << "���ڼ�ˮ" << endl;
    }
    void addsomething(){
        cout << "���ڼӲ�Ҷ" << endl;
    }
    ~tea(){
        cout << "tea����������" <<endl;
    }
};

class coffee:public drink
{public:
    coffee(){
        cout << "coffee�Ĺ��캯��" <<endl;
    }
    void boil(){
        cout << "�����տ�" << endl;
    }
    void addwater(){
        cout << "���ڼ�ˮ" << endl;
    }
    void addsomething(){
        cout << "���ڼӿ��ȶ�" << endl;
    }
    ~coffee(){
        cout << "coffee����������" <<endl;
    }
};

void make(drink *drink){
    drink->make();
    delete drink;
}//�����Ǿ��裬�����ָ����������������������ԶԲ�ͬ�����࣬�����в�һ���Ĳ�����������ͳһ�����ڴ�
//
//
//�������drink������������������������ô�ͷ��ڴ��ʱ����ִ���˸����������������û��ִ���������������,delete drinkִ�е��Ǹ�����ڴ��ͷţ���������ڴ沢û�б��ͷţ�
//������Ϊ�����������������ô�������麯��һ�������������ĵ�ַ�ڱ����ʱ����Ѿ����ˣ���������麯����Ϊ��������������ô�ͻ����е�ʱ���ٽ��е�ַ��ѡ��
//
//

int main(){
    // tea t1;//���tea����û�иı�boil�ȵȵĴ��麯���������ǲ��Ϸ��ģ���Ϊ��������Ϊtea�ǳ�����
    make(new coffee);
    system("pause");
}