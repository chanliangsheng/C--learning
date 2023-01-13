#include <iostream>
#include <string>

using namespace std;


class cpu{
public:
    virtual void compute() = 0;//
};//������cpu

class Graphics_card{
public:
    virtual void show() = 0;
};//�������Կ�

class Memory_module{
public:
    virtual void store() = 0;
};//�������ڴ���

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
//Ӣ�ض����������

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
//������������


class computer{
public:
    computer(){
        m_cpu = new intel_Cpu;
        m_Graphics_card = new intel_Graphics_card;
        m_Memory_module = new intel_Memory_module;
    }//Ĭ�Ϲ��캯�������Ĭ�ϣ��ʹ�������intel�����

    computer(cpu* cpu, Graphics_card* Graphics_card, Memory_module* Memory_module):m_cpu(cpu),m_Graphics_card(Graphics_card),m_Memory_module(Memory_module)
    {
    }//�вι��캯�����������������ĵ�ַ�����ܲ���

    void show(){
        m_cpu->compute();
        m_Graphics_card->show();
        m_Memory_module->store();
    }//���м������������Ϊ

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
    }//��Ҫ�ͷŴ洢��3��ָ��
private:
    cpu* m_cpu;
    Graphics_card* m_Graphics_card;
    Memory_module* m_Memory_module;
    //�����������
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