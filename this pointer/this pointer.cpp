#include <iostream>

using namespace std;
class person{
public:
    int age;
    
    person add_age(int age){
        this->age += age;
        return *this;
    }//��������

    person(){
        age = 0;
        cout << "���ù��캯��" << endl;
    }
};


int main(){

    person p1;
    p1.add_age(10).add_age(10);
    cout << p1.age;
    system("pause");
}