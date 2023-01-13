#include <iostream>

using namespace std;

class Box{
private:
    double m_L;
    double m_H;
    double m_W;

public:
    void set(double L , double H , double W){
        m_H = H;
        m_L = L;
        m_W = W;
    }//���ó�����

    void get_area(){
       double area = 2*m_L*m_H + 2*m_L*m_W + 2*m_W*m_H;
       cout << "���Ϊ�� "<< area << endl;
    }//���

    void get_volume(){
        double volume = m_L*m_H*m_W;
        cout << "���Ϊ: " << volume << endl;
    }

};

int main(){
   cout << "胡思彤大屁股";

    system("pause");
}