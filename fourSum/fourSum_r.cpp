#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort
#include <conio.h>
#include <map>
#include <utility>
using namespace std;

vector<int> sort_indexes(vector<int> &v) {

  // initialize original index locations
  vector<int> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings
  // when v contains elements of equal values 
  stable_sort(idx.begin(), idx.end(),
       [&v](int i1, int i2) {return v[i1] < v[i2];});

  return idx;
}

std::vector<std::vector<int>> fourSum(std::vector<int> chain ,std::vector<int> unsaturation ,std::vector<int> oxygen, int target_chain , int target_unsaturation , int target_oxygen){
  using namespace std;//使用std命名空间
  //双指针法解决四数之和
  vector<vector<int>> res;//预定义结果数组
  vector<int> match_order = sort_indexes(chain);

  for(int i = 0; i < chain.size(); i++){
    if(chain[match_order[i]]*4 > target_chain){
      break;
    }
    //如果i对应的chain4条FA加起来已经大于目标值，则跳过此次循环
    for (int j = i; j < chain.size(); j++)
    {
      if((chain[match_order[i]] + chain[match_order[j]]*3) > target_chain){
        break;
      }
      //如果i对应的chain和j对应的总共4条FA加起来已经大于目标值，则跳过此次循环，因为left和right都比j和i大
      int left = j;
      int right = chain.size() - 1;
      //初始化left和right
      while (left <= right)
      {
        if ( ((chain[match_order[i]] + chain[match_order[j]] +chain[match_order[left]] + chain[match_order[right]]) == target_chain) && ((unsaturation[match_order[i]] + unsaturation[match_order[j]] +unsaturation[match_order[left]] + unsaturation[match_order[right]]) == target_unsaturation) && ((oxygen[match_order[i]] + oxygen[match_order[j]] + oxygen[match_order[left]] + oxygen[match_order[right]]) == target_oxygen) )
        {
          res.push_back({match_order[i] + 1 , match_order[j] + 1 , match_order[left] + 1 , match_order[right] + 1});//如果找到这个三元组，下标加入结果数组
          int left_t = left;
          int right_t = right;//暂时的left和right
          while ( (chain[match_order[left_t]] == chain[match_order[left_t + 1]]) && (unsaturation[match_order[left_t]] == unsaturation[match_order[left_t + 1]]) && (oxygen[match_order[left_t]] == oxygen[match_order[left_t + 1]]) )
          {
            res.push_back({match_order[i] + 1 ,match_order[j] + 1, match_order[left_t] + 1 , match_order[right] + 1});//当left的右边一个和left的值相同，则把这个三元组存储到结果中
            left_t++;
          }
          right--;

        }
        else if((chain[match_order[i]] + chain[match_order[j]] + chain[match_order[left]] + chain[match_order[right]]) > target_chain){
          right--;//如果比目标值大，则最右边向左移
        }
        else if((chain[match_order[i]] + chain[match_order[j]] + chain[match_order[left]] + chain[match_order[right]]) < target_chain){
          left++;//如果比目标值小，则最左边向右移
        }
        else if((chain[match_order[i]] + chain[match_order[j]] +chain[match_order[left]] + chain[match_order[right]]) == target_chain){
          //如果chain加起来等于target，但是其他加起来不等于
          int left_t = left;
          int right_t = right;//暂时的left和right
          while (chain[match_order[left_t]] == chain[match_order[left_t + 1]] && (left_t + 1 < right_t)){
            if (((unsaturation[match_order[i]] + unsaturation[match_order[j]] +unsaturation[match_order[left_t + 1]] + unsaturation[match_order[right]]) == target_unsaturation) && ((oxygen[match_order[i]] + oxygen[match_order[j]] + oxygen[match_order[left_t + 1]] + oxygen[match_order[right]]) == target_oxygen))
            {
                res.push_back({match_order[i] + 1 ,match_order[j] + 1, match_order[left_t + 1] + 1 , match_order[right] + 1});
            }
            left_t++;
          }
          right--;
          //赋值
        }
      }
    }
  }

  return(res);
}


int main(){
    auto chain = {12, 13, 13, 16, 16, 17, 18, 19, 19, 20, 20, 20, 20, 21, 21, 21, 21, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 26, 26, 26};
    auto unsaturation = {0, 1, 0, 0, 1, 0, 0, 1, 0, 4, 2, 1, 0, 1, 0, 1, 0, 0, 2, 1, 0, 5, 3, 2, 1, 5, 1, 0, 4, 5, 2, 1, 5, 0, 5, 1, 0, 4, 6, 6, 5, 4};
    auto oxygen = {0, 0, 1, 3, 2, 1, 0, 6, 7, 0, 4, 5, 5, 6, 7, 3, 4, 2, 7, 8, 9, 6, 5, 6, 7, 3, 6, 7, 4, 5, 4, 5, 2, 6, 0, 3, 4, 1, 6, 4, 5, 6};
    int target_chain = 85;
    int target_unsaturation = 9;
    int target_oxygen = 9;
    auto result = fourSum(chain , unsaturation ,oxygen , target_chain , target_unsaturation,target_oxygen);
    cin.get();
}