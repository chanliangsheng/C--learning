#include <iostream>
#include <string>

using namespace std;


class cpu{
public:
    virtual void compute() = 0;//
};//抽象类cpu

class Graphics_card{
public:
    virtual void show() = 0;
};//抽象类显卡

class Memory_module{
public:
    virtual void store() = 0;
};//抽象类内存条

class intel_Cpu:public cpu
{
public:
    void compute(){
        cout << "intel cpu is computing..." << endl;
    }
};
class intel_Graphics_card:public Graphics_card
{
public:
    void show(){
        cout << "intel Graphics_card is computing..." << endl;
    }
};
class intel_Memory_module:public Memory_module
{
public:
    void store(){
        cout << "intel Memory_module is computing..." << endl;
    }
};
//英特尔的三种零件

class lenvo_Cpu:public cpu
{
public:
    void compute(){
        cout << "lenvo cpu is computing..." << endl;
    }
};

class lenvo_Graphics_card:public Graphics_card
{
public:
    void show(){
        cout << "lenvo Graphics_card is computing..." << endl;
    }
};

class lenvo_Memory_module:public Memory_module
{
public:
    void store(){
        cout << "lenvo Memory_module is computing..." << endl;
    }
};
//联想的三种零件


class computer{
public:
    computer(){
        m_cpu = new intel_Cpu;
        m_Graphics_card = new intel_Graphics_card;
        m_Memory_module = new intel_Memory_module;
    }//默认构造函数，如果默认，就创建都是intel的零件

    computer(cpu* cpu, Graphics_card* Graphics_card, Memory_module* Memory_module):m_cpu(cpu),m_Graphics_card(Graphics_card),m_Memory_module(Memory_module)
    {
    }//有参构造函数，利用输入的零件的地址来接受参数

    void show(){
        m_cpu->compute();
        m_Graphics_card->show();
        m_Memory_module->store();
    }//进行计算机的三种行为

    ~computer(){
        if (m_cpu != NULL)
        {
            cout << "delete cpu" << endl;
           delete m_cpu;
        }

        if (m_Graphics_card != NULL)
        {
            cout << "delete Graphics_card" << endl;
            delete m_Graphics_card;
        }
        
        if (m_Memory_module != NULL)
        {
            cout << "delete Memory_module" << endl;
            delete m_Memory_module;
        }
    }//需要释放存储的3个指针
private:
    cpu* m_cpu;
    Graphics_card* m_Graphics_card;
    Memory_module* m_Memory_module;
    //接受三种零件
};


void assable(){
    computer *c1 = new computer(new lenvo_Cpu , new intel_Graphics_card , new lenvo_Memory_module);
    c1->show();
    delete c1;
}

int main(){
    assable();
    system("pause");
}