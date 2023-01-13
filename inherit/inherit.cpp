#include <iostream>
#include <string>

using namespace std;

class father{
public:
    int a;
    int b;
    int c;
    father(){
        a = 2;
        b = 2;
        c = 2;
    }
};

class son:public father{
public:
    int a;
};


int main(){
    son s1;
    cout << s1.father::a << endl;//父类的a会复制一份到子类中，调用了拷贝构造函数
    system("pause");
}