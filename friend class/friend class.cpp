#include <iostream>
#include <string>
using namespace std;

//���ʾ���ϣ��һЩ����Ķ������Է������ڵ�private���ԣ���������Ԫ�࣬ȫ�ֺ�����Ԫ����Ա������Ԫ�����ǲ�ͬ�����µ�ʹ��

class Room{
    friend class goodGay;//goodGay��Ϊ��Ԫ������goodGay��������Room��private����
public:
    string livingroom;
private:
    string bedroom;
public:
    Room(){
        livingroom = "����";
        bedroom = "����";
    }//���캯��
};

class goodGay{
public:
    Room* buliding;
    goodGay(){
       buliding = new Room;
    }//���캯��Ϊ�½�һ��Room�࣬������bulidingָ�������

    void visit(){
        cout << "�û������ڷ���" << buliding->bedroom;
        cout << "�û������ڷ���" << buliding->livingroom;
    }
};

void test(){
    goodGay gg;
    gg.visit();
}

int main(){
    test();

    system("pause");
}