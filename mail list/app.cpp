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
    };//定义每个人的所有信息

void add(vector<person> *store){
    char name;
    char sex;
    int age;
    char phone;
    char home_address;
    person new_person;

    cout << "请输入联系人的名字：";
    cin >> new_person.name;

    cout << "请输入联系人的性别：";
    cin >> new_person.sex;

    cout << "请输入联系人的年龄：";
    cin >> new_person.age;

    cout << "请输入联系人的手机号：";
    cin >> new_person.phone;

    cout << "请输入联系人的家庭住址：";
    cin >> new_person.home_address;
    
    store->push_back(new_person);
    // 追加一个person的信息
    // *store->push_back(new_person);无效，因为->是用于指针的，而*store是指指针指向的位置，但是由于只有变量名+.才可以使用push_back方法，所以只能这样做

}//增加联系人

void show(vector<person> *store){
    int store_length = store->size();//计算store的长度
    for (int i = 0; i < store_length; i++)
    {
        cout <<  "名字:" <<(*store)[i].name << "    性别:" << (*store)[i].sex << "  年龄:" << (*store)[i].age << "  手机号:" << (*store)[i].phone <<  " 家庭住址:" << (*store)[i].home_address << endl;
    }
}//显示所有联系人


int main(){
    int behavior;
    
    vector<person> store;// 指针和变量要对称声明，不能只有指针，因为指针只是分配了一个地址，只是指向了某个地方，而那个地方是哪还是未知的
    while(1){
        cout << "1.添加联系人" << endl 
         << "2.显示所有联系人" << endl
         << "3.删除某个联系人" << endl
         << "4.查找某个联系人" << endl
         << "5.清空所有联系人的信息" << endl
         << "6.退出通讯率" << endl << endl;
        cout << "请输入你想进行的操作：";

        cin >> behavior;//将用户的行为输入到behavior中
        switch (behavior)
            {
            case 1:
                add(&store);
                break;
            case 2:
                show(&store);
                cout << endl << endl << endl <<"输入任意键退出";
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
            system("CLS");//清空cmd窗口
    }
}