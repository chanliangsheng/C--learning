#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct person
    {
        string name;
        string sex;
        int age;
        string phone;
        string home_address;
    };//����ÿ���˵�������Ϣ

void add(vector<person> *store){
    char name;
    char sex;
    int age;
    char phone;
    char home_address;
    person new_person;

    cout << "��������ϵ�˵����֣�";
    cin >> new_person.name;

    cout << "��������ϵ�˵��Ա�";
    cin >> new_person.sex;

    cout << "��������ϵ�˵����䣺";
    cin >> new_person.age;

    cout << "��������ϵ�˵��ֻ��ţ�";
    cin >> new_person.phone;

    cout << "��������ϵ�˵ļ�ͥסַ��";
    cin >> new_person.home_address;
    
    store->push_back(new_person);
    // ׷��һ��person����Ϣ
    // *store->push_back(new_person);��Ч����Ϊ->������ָ��ģ���*store��ָָ��ָ���λ�ã���������ֻ�б�����+.�ſ���ʹ��push_back����������ֻ��������

}//������ϵ��

void show(vector<person> *store){
    int store_length = store->size();//����store�ĳ���
    for (int i = 0; i < store_length; i++)
    {
        cout <<  "����:" <<(*store)[i].name << "    �Ա�:" << (*store)[i].sex << "  ����:" << (*store)[i].age << "  �ֻ���:" << (*store)[i].phone <<  " ��ͥסַ:" << (*store)[i].home_address << endl;
    }
}//��ʾ������ϵ��


int main(){
    int behavior;
    
    vector<person> store;// ָ��ͱ���Ҫ�Գ�����������ֻ��ָ�룬��Ϊָ��ֻ�Ƿ�����һ����ַ��ֻ��ָ����ĳ���ط������Ǹ��ط����Ļ���δ֪��
    while(1){
        cout << "1.�����ϵ��" << endl 
         << "2.��ʾ������ϵ��" << endl
         << "3.ɾ��ĳ����ϵ��" << endl
         << "4.����ĳ����ϵ��" << endl
         << "5.���������ϵ�˵���Ϣ" << endl
         << "6.�˳�ͨѶ��" << endl << endl;
        cout << "������������еĲ�����";

        cin >> behavior;//���û�����Ϊ���뵽behavior��
        switch (behavior)
            {
            case 1:
                add(&store);
                break;
            case 2:
                show(&store);
                cout << endl << endl << endl <<"����������˳�";
                cin >> behavior;
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            case 5:
                /* code */
                break;
            case 6:
                /* code */
                break;
            }
            if(behavior == 6){
                break;
            }
            system("CLS");//���cmd����
    }
}