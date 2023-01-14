#include <iostream>
#include "test.h"

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
    }//ï¿½ï¿½ï¿½Ã³ï¿½ï¿½ï¿½ï¿½ï¿½

    void get_area(){
       double area = 2*m_L*m_H + 2*m_L*m_W + 2*m_W*m_H;
       cout << "ï¿½ï¿½ï¿½Îªï¿½ï¿? "<< area << endl;
    }//ï¿½ï¿½ï¿?

    void get_volume(){
        double volume = m_L*m_H*m_W;
        cout << "ï¿½ï¿½ï¿½Î?: " << volume << endl;
    }

};

int main(){
   cout << "Fdasf";

    system("pause");
}