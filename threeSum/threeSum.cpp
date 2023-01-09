#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort
#include <conio.h>
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

vector<vector<int>> threeSum(vector<int> chain , int target){
    //双指针法解决三数之和
    vector<vector<int>> res;//预定义结果数组
    vector<int> match_order = sort_indexes(chain);//进行排序，返回下标
    for (int i = 0; i < chain.size(); i++)
    {
        int left = i;
        int right = chain.size();
        //初始化left和right
        while (left <= right)
        {
            if ((chain[match_order[i]] + chain[match_order[left]] + chain[match_order[right]]) == target)
            {
                res.push_back({match_order[i] + 1 , match_order[left] + 1 , match_order[right] + 1});//如果找到这个三元组，下标加入结果数组
                int left_t = left;
                int right_t = right;//暂时的left和right
                while (chain[match_order[left_t]] == chain[match_order[left_t + 1]])
                {
                    res.push_back({match_order[i] + 1 , match_order[left_t] + 1 , match_order[right] + 1});//当left的右边一个和left的值相同，则把这个三元组存储到结果中
                    left_t++;
                }
                right--;
                
            }
            else if((chain[match_order[i]] + chain[match_order[left]] + chain[match_order[right]]) > target){
                right--;//如果比目标值大，则最右边向左移
            }
            else if((chain[match_order[i]] + chain[match_order[left]] + chain[match_order[right]]) < target){
                left++;//如果比目标值小，则最左边向右移
            }
        }
    }
    return(res);
}

int main(){
    cout<<"test";
}