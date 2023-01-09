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


vector<vector<int>>  matchMS1_cpp_fast_left_right(vector<int>  nums, vector<int>  min_match , vector<int>  max_match){
  vector<vector<int>> res;//预定义结果数组

  vector<int> match_order = sort_indexes(min_match);//进行排序
  

  int num_len=nums.size();//获取数据长度；
  for(int i=0;i<num_len;++i){

    vector<int> store;//每次循环重新定义store
    store.push_back(i+1);//追加i+1
      int left = 0;
      int right = min_match.size() - 1;
      while(left <= right){
        int mid = (left + right)/2;//中值
        if(nums[i] > min_match[match_order[mid]] && nums[i] < max_match[match_order[mid]]){
          store.push_back(match_order[mid] + 1);//将捕捉到的放到store中，坐标加一
          int left_mid = mid - 1;
          int right_mid = mid + 1;
          while(left_mid >= left && nums[i] > min_match[match_order[left_mid]] && nums[i] < max_match[match_order[left_mid]]){
            store.push_back(match_order[left_mid] + 1);//将捕捉到的放到store中，坐标加一
            left_mid--;56
          }//捕捉mid左边符合要求的
          while(right_mid <= right && nums[i] > min_match[match_order[right_mid]] && nums[i] < max_match[match_order[right_mid]]  ){
            store.push_back(match_order[right_mid] + 1);//将捕捉到的放到store中，坐标加一
            right_mid++;
          }//捕捉mid右边符合要求的
		  break;
        }
        else if(nums[i] > min_match[match_order[mid]]){
          left = mid + 1;
        }
        else if(nums[i] < max_match[match_order[mid]]){
          right = mid - 1;
        }
      }

    if(store.size() != 1){
      res.push_back(store);//将store追加到res中
    }
    //如果有配对上数据库，则放入res中
  }
  return res;
}
// 列表中第一个元素的nums的位置，后面的是这个位置匹配到的最大值和最小值之间的位置



int main(){
	auto nums={1,2,3,4,5,6};
	auto min_match = {5,6,7,8,9,10,11,12,1};
	auto max_match = {7,8,9,10,11,12,13,14,3};
	auto result = matchMS1_cpp_fast_left_right(nums , min_match , max_match);
	return(0);
}