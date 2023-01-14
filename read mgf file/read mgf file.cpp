#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>
#include <utility>
#include <algorithm>
#include "boost/lexical_cast.hpp"
using namespace std;

ostream& operator<<(ostream &cout , pair<double , double> &p){//cout需要传递引用，因为流对象是花销很多的，如果传递副本会过大开销，所以只允许传递引用
    cout << "mz:" << p.first << "   " 
    <<"intensity:" << p.second << endl;
    return cout;
}//重载pair的<<运算符

class MS2{
public:
    MS2& set_Precursor_ion(double &mz ,double &intensity){
        this->m_Precursor_ion = pair(mz , intensity);
        return *this;
    }//设置MS2类的前体离子信息，返回引用

    MS2& set_rt(double &rt){
        this->m_rt = rt;
        return *this;
    }//设置rt信息

    MS2& append_Fragment_ion(pair<double , double> &Fragment_ion){
        this->m_Fragment_ion.push_back(Fragment_ion);//用不复制的方式来复制
        return *this;
    }//往对象中追加pair的属性

    void show_Precursor_ion(){
        cout << this->m_Precursor_ion << endl;
    }//显示前体离子的信息
    
// private:
    pair<double , double> m_Precursor_ion;
    double m_rt;//保留时间
    vector<pair<double, double>> m_Fragment_ion;//碎片离子的构成，为一个向量，向量中的成员为pair，每个pair存储mz和对应的intensity
};//一个MS2的类


vector<MS2> scanMgf(string file_name = "D://R package//data//mzml(idx)//NEG_ID_01.mgf"){
    ifstream ifs;

    vector<MS2> store;
    ifs.open(file_name , ios::in);//以读取的方式打开文件

    if(!ifs.is_open()){
        cout << "无法打开该文件..." << endl;
        return store;
    }
    //如果无法打开的话，直接返回

    string buf;//存储每一行的字符
    string buf_inside;
    std::string::size_type sz;//string转化为double的标识符
    while (getline(ifs , buf))
    {   
        int count = 1;
        MS2 m;//新建一个m类
        while (buf == "BEGIN IONS")
        {
            getline(ifs , buf_inside);//读取下一行
            if(buf_inside == "END IONS"){
                store.push_back(m);
                break;   
            }
            //如果是END IONS行，则退出这个while,将对象m追加到store中
            count ++;
            if (count == 2)
            {
                continue;
            }
            //如果是BEGIN IONS的下一行，则不把信息载入
            if (count == 3)
            {
               int pos = buf_inside.find_first_of("=");//找到等号的位置
               double rt = stod(buf_inside.substr(pos + 1));//把字符串转化成double
               m.set_rt(rt);//设置rt
            }
            //如果是第三行，则提取rt放入对象m中
            if(count == 4){
                int equal_pos = buf_inside.find_first_of("=");
                buf_inside = buf_inside.substr(equal_pos + 1);//去除等号前面的部分
                int pos = buf_inside.find_first_of(" ");//找到空格的位置
                double mz = stod(buf_inside.substr(0, pos));
                double intensity = stod(buf_inside.substr(pos + 1));//生成前体离子的mz和intensity
                // m.set_Precursor_ion();
                m.set_Precursor_ion(mz , intensity);//加入到m对象的前体离子信息中
            }

            if (count == 5)
            {
                int pos = buf_inside.find_first_of("=");//找到等号的位置
                if (pos > 0)
                {
                    continue;
                }//如果里面又等号，说明不是mz和intensity
                else{
                    pos = buf_inside.find_first_of(" ");//找到空格的位置
                    double mz = stod(buf_inside.substr(0, pos));
                    double intensity = stod(buf_inside.substr(pos + 1));
                    pair<double , double> p1 = make_pair(mz , intensity);
                    m.append_Fragment_ion(p1);//为了传递引用
                    //往对象m追加属性到碎片的信息中
                }
            }

            if (count > 5)
            {
                int pos = buf_inside.find_first_of(" ");//找到空格的位置
                double mz = stod(buf_inside.substr(0, pos));
                double intensity = stod(buf_inside.substr(pos + 1));
                // pair<double , double> p1 = make_pair(mz , intensity);
                // m.append_Fragment_ion(p1);
                // 往对象m追加属性到碎片的信息中
                
                // int pos = buf_inside.find_first_of(" ");//找到空格的位置
                // double mz = stod(string(buf_inside.begin() , buf_inside.begin() + pos));
                // double intensity = stod(string(buf_inside.begin() + pos + 1 , buf_inside.end()));
                // pair<double , double> p1 = make_pair(mz , intensity);
                // m.append_Fragment_ion(p1);
            }
            
        }//如果读取到BEGIN IONS，则进行这些操作     
    }
    ifs.close();//关闭文件
    cout << "done！";

    
    return store;
}//扫描mgf文件的函数

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