#include <iostream>
#include <string>

using namespace std;

class animal{
public:
    // void speak(){
    //     cout << "������˵��";
    // }
    virtual void speak(){
        cout << "������˵��";
    }
};

class cat:public animal
{
    void speak(){
        cout << "è��˵��";
    }

    void speak2(){
        cout << "è2��˵��";
    }
};

class dog:public animal
{
    void speak(){
        cout << "����˵��";
    }
};

void speak_(animal &animal){
    animal.speak();
    // animal.speak2();
    // ��������ˣ���Ϊ�������animal�࣬�������ڵ�ʱ��Ű�animal����ǿ��ת��Ϊcat����
}

int main(){
    cat c1;
    speak_(c1);//���������Ϊè��ʱ�򣬻���ִ���˶������е�speak����;������Ϊspeak_�����ڱ������Ͱ�animal.speak()�����ĵ�ַ����,���۴������ʲô���󣬶�ִ��animal��speak������
    //���������speak�ĵ�ַ�Ȱ󶨣����ǰ������Ǵ���Ķ�����ȷ��������ַ����ô��Ҫ��animal��speak������Ϊ�麯��
    system("pause");
}