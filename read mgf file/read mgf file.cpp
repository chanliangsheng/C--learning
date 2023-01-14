#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>
#include <utility>
#include <algorithm>
#include "boost/lexical_cast.hpp"
using namespace std;

ostream& operator<<(ostream &cout , pair<double , double> &p){//cout��Ҫ�������ã���Ϊ�������ǻ����ܶ�ģ�������ݸ����������������ֻ����������
    cout << "mz:" << p.first << "   " 
    <<"intensity:" << p.second << endl;
    return cout;
}//����pair��<<�����

class MS2{
public:
    MS2& set_Precursor_ion(double &mz ,double &intensity){
        this->m_Precursor_ion = pair(mz , intensity);
        return *this;
    }//����MS2���ǰ��������Ϣ����������

    MS2& set_rt(double &rt){
        this->m_rt = rt;
        return *this;
    }//����rt��Ϣ

    MS2& append_Fragment_ion(pair<double , double> &Fragment_ion){
        this->m_Fragment_ion.push_back(Fragment_ion);//�ò����Ƶķ�ʽ������
        return *this;
    }//��������׷��pair������

    void show_Precursor_ion(){
        cout << this->m_Precursor_ion << endl;
    }//��ʾǰ�����ӵ���Ϣ
    
// private:
    pair<double , double> m_Precursor_ion;
    double m_rt;//����ʱ��
    vector<pair<double, double>> m_Fragment_ion;//��Ƭ���ӵĹ��ɣ�Ϊһ�������������еĳ�ԱΪpair��ÿ��pair�洢mz�Ͷ�Ӧ��intensity
};//һ��MS2����


vector<MS2> scanMgf(string file_name = "D://R package//data//mzml(idx)//NEG_ID_01.mgf"){
    ifstream ifs;

    vector<MS2> store;
    ifs.open(file_name , ios::in);//�Զ�ȡ�ķ�ʽ���ļ�

    if(!ifs.is_open()){
        cout << "�޷��򿪸��ļ�..." << endl;
        return store;
    }
    //����޷��򿪵Ļ���ֱ�ӷ���

    string buf;//�洢ÿһ�е��ַ�
    string buf_inside;
    std::string::size_type sz;//stringת��Ϊdouble�ı�ʶ��
    while (getline(ifs , buf))
    {   
        int count = 1;
        MS2 m;//�½�һ��m��
        while (buf == "BEGIN IONS")
        {
            getline(ifs , buf_inside);//��ȡ��һ��
            if(buf_inside == "END IONS"){
                store.push_back(m);
                break;   
            }
            //�����END IONS�У����˳����while,������m׷�ӵ�store��
            count ++;
            if (count == 2)
            {
                continue;
            }
            //�����BEGIN IONS����һ�У��򲻰���Ϣ����
            if (count == 3)
            {
               int pos = buf_inside.find_first_of("=");//�ҵ��Ⱥŵ�λ��
               double rt = stod(buf_inside.substr(pos + 1));//���ַ���ת����double
               m.set_rt(rt);//����rt
            }
            //����ǵ����У�����ȡrt�������m��
            if(count == 4){
                int equal_pos = buf_inside.find_first_of("=");
                buf_inside = buf_inside.substr(equal_pos + 1);//ȥ���Ⱥ�ǰ��Ĳ���
                int pos = buf_inside.find_first_of(" ");//�ҵ��ո��λ��
                double mz = stod(buf_inside.substr(0, pos));
                double intensity = stod(buf_inside.substr(pos + 1));//����ǰ�����ӵ�mz��intensity
                // m.set_Precursor_ion();
                m.set_Precursor_ion(mz , intensity);//���뵽m�����ǰ��������Ϣ��
            }

            if (count == 5)
            {
                int pos = buf_inside.find_first_of("=");//�ҵ��Ⱥŵ�λ��
                if (pos > 0)
                {
                    continue;
                }//��������ֵȺţ�˵������mz��intensity
                else{
                    pos = buf_inside.find_first_of(" ");//�ҵ��ո��λ��
                    double mz = stod(buf_inside.substr(0, pos));
                    double intensity = stod(buf_inside.substr(pos + 1));
                    pair<double , double> p1 = make_pair(mz , intensity);
                    m.append_Fragment_ion(p1);//Ϊ�˴�������
                    //������m׷�����Ե���Ƭ����Ϣ��
                }
            }

            if (count > 5)
            {
                int pos = buf_inside.find_first_of(" ");//�ҵ��ո��λ��
                double mz = stod(buf_inside.substr(0, pos));
                double intensity = stod(buf_inside.substr(pos + 1));
                // pair<double , double> p1 = make_pair(mz , intensity);
                // m.append_Fragment_ion(p1);
                // ������m׷�����Ե���Ƭ����Ϣ��
                
                // int pos = buf_inside.find_first_of(" ");//�ҵ��ո��λ��
                // double mz = stod(string(buf_inside.begin() , buf_inside.begin() + pos));
                // double intensity = stod(string(buf_inside.begin() + pos + 1 , buf_inside.end()));
                // pair<double , double> p1 = make_pair(mz , intensity);
                // m.append_Fragment_ion(p1);
            }
            
        }//�����ȡ��BEGIN IONS���������Щ����     
    }
    ifs.close();//�ر��ļ�
    cout << "done��";

    
    return store;
}//ɨ��mgf�ļ��ĺ���

int main(){
    // ifstream ifs;
    // vector<MS2> store;
    // string file_name = "D://R package//data//mzml(idx)//NEG_ID_01.mgf";
    // ifs.open(file_name , ios::in);
    // string buf;
    // getline(ifs , buf);
    // cout << buf << endl;

    // getline(ifs , buf);
    // cout << buf << endl;

    // auto result = scanMgf();
    auto start = std::chrono::high_resolution_clock::now();

    auto result = scanMgf();

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds >(stop - start);

    std::cout << "Time taken by function: "
              << duration.count() << " seconds " << std::endl;

    // int count = 0;
    // for (size_t i = 0; i < result.size(); i++)
    // {
    //     cout << result[i].m_Fragment_ion.size() << endl;
    //     count += result[i].m_Fragment_ion.size() * sizeof(pair<double , double>);

    //     count += sizeof(result[i].m_rt);
    //     count += sizeof(result[i].m_Precursor_ion);
    // }
    
    // cout << count/(1024*1024) << endl;


    system("pause");
}