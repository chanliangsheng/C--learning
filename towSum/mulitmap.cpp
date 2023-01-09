#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <conio.h>
using namespace std;

auto mulit_map(multimap<int , int> hashmap, int key){
    vector<int> result;
    auto it = hashmap.equal_range(key);//求与哈希表中相同key的范围，it返回的是两个迭代器，一个左边，一个右边
    for (auto itr = it.first; itr != it.second; ++itr) {
        result.push_back(itr -> second);//将迭代器的second属性(key对应的值)放入结果向量中
    }
    return(result);
}

int main()
{
 
    // initialize container
    multimap<int, int> mp;
    // insert elements in random order
    mp.insert({ 2, 30 });
    mp.insert({ 1, 40 });
    mp.insert({ 3, 60 });
    mp.insert({ 1, 20 });
    mp.insert({ 5, 50 });
    mp.insert({ 1, 90 });
 
    // Stores the range of key 1
    auto it = mp.equal_range(1);
 
    cout << "The multimap elements of key 1 is : \n";
    cout << "KEY\tELEMENT\n";
    auto result = mulit_map(mp , 10);
    
    cout << result.size();

    for (auto itr = result.begin(); itr != result.end(); itr++)
    {
        cout << *itr << endl;
    }
    
    cin.get();
    return 0;
}