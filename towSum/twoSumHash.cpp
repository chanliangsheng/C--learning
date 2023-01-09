#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <conio.h>
using namespace std;

std::vector<std::vector<int>> twoSum_non_duplicate(std::vector<int> chain ,std::vector<int> unsaturation ,std::vector<int> oxygen, int target_chain , int target_unsaturation , int target_oxygen) {
  using namespace std;//使用std命名空间
  vector<vector<int>> store;
  multimap<int,int> hash_map;//提供一对多的hash

  for(auto i = 0;i < chain.size();i++){
    auto it = hash_map.equal_range(target_chain - chain[i]);//寻找与key相同的下标
    
    if(it.first == hash_map.end() & it.second == hash_map.end()){

    }
    else{
      for (auto itr = it.first; itr != it.second; ++itr) {//itr是迭代器，存储的是pair，first属性是key，second属性是key对应的value
        //如果两个FA的chain加起来等于target值，判断这两个FA的unsaturation和oxygen分别加起来是否等于target值
        if((unsaturation[i] + unsaturation[itr->second] == target_unsaturation) & (oxygen[i] + oxygen[itr->second] == target_oxygen)){
          store.push_back({i + 1 , (itr->second) + 1});//将迭代器的second属性(key对应的下标)放入结果向量中
        }
      }
      //如果找到了，则存入store中
    }
    hash_map.insert({chain[i] , i});//value 作为key ，i作为下标存入哈希表中
  }
  return store;

}


int main(){
    vector<int> A = {0,1,2,3,4,5,6,7,7,1,1};
    int target = 8;
    auto result = twoSum_non_duplicate({16,18,18,20} ,  {1,1,1,4} , {0,0,0,0} ,  34 , 2 , 0);
    
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << " ";
        cout << result[i][1];
        cout << "\n";
    }
    _getch();
    return 0;
}