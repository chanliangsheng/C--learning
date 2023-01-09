#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort
#include <conio.h>
#include <map>
#include <set>
using namespace std;

//M_H_mz和M_2H_mz需要已经排好序
vector<vector<vector<int>>> matchMS1_separate(vector<double> nums ,vector<double> M_H_mz ,vector<double> M_2H_mz ,int ppm){

    std::sort(M_H_mz.begin() , M_H_mz.end());
    std::sort(M_2H_mz.begin() , M_2H_mz.end());//排序

    vector<double> M_H_mz_min_match(M_H_mz.size());
    vector<double> M_H_mz_max_match(M_H_mz.size());//初始化

    vector<double> M_2H_mz_min_match(M_2H_mz.size());
    vector<double> M_2H_mz_max_match(M_2H_mz.size());//初始化

    std::transform(M_H_mz.begin() , M_H_mz.end() , M_H_mz_min_match.begin() , [ppm](double mz){return mz - mz*ppm/1000000;});
    std::transform(M_H_mz.begin() , M_H_mz.end() , M_H_mz_max_match.begin() , [ppm](double mz){return mz + mz*ppm/1000000;});

    std::transform(M_2H_mz.begin() , M_2H_mz.end() , M_2H_mz_min_match.begin() , [ppm](double mz){return mz - mz*ppm/1000000;});
    std::transform(M_2H_mz.begin() , M_2H_mz.end() , M_2H_mz_max_match.begin() , [ppm](double mz){return mz + mz*ppm/1000000;});
    //计算配对的最大值和最小值



    int num_len = nums.size();//获取数据长度；
    vector<vector<int>> M_H_res;//定义M-H的搜索结果
    vector<vector<int>> M_2H_res;//定义M-2H的搜索结果
    vector<vector<int>> M_H_M_2H_res;//既有M-H又有M-2H的搜索结果
    set<int> M_H_cut_index;//定义需要删除的M-H中的下标
    multimap<int, int> mp;//创建多重哈希表
    
    for(int i = 0;i < num_len ; ++i){
    // 用i遍历nums数组
    int left = 0;
    int right = M_H_mz_min_match.size() - 1;
    while(left <= right){
      int mid = (left + right)/2;//中值
      if(nums[i] >= M_H_mz_min_match[mid] && nums[i] <= M_H_mz_max_match[mid]){
        // 如果nums数组符合要求(处于M-H数据库中某个数据的5个ppm中)
        M_H_res.push_back({i , mid});//将捕捉到的放到M_H_res中
        mp.insert({mid , M_H_res.size() - 1});//将M-H配对到的位置mid作为哈希表的键，M_H结果数组的下标作为值，存储到哈希表中
        int left_mid = mid - 1;
        int right_mid = mid + 1;

        while(left_mid >= left && nums[i] >= M_H_mz_min_match[left_mid] && nums[i] <= M_H_mz_max_match[left_mid]){
          M_H_res.push_back({left_mid}); //因为mid左边可能还有符合条件的，所以向左循环寻找
          mp.insert({left_mid , M_H_res.size() - 1});//加入哈希表
          left_mid--;
        }//捕捉mid左边符合要求的

        while(right_mid <= right && nums[i] >= M_H_mz_min_match[right_mid] && nums[i] <= M_H_mz_max_match[right_mid]){
          M_H_res.push_back({right_mid}); //因为mid右边可能还有符合条件的，所以向左循环寻找
          mp.insert({right_mid , M_H_res.size() - 1});//加入哈希表
          right_mid++;
        }//捕捉mid右边符合要求的

        break;//找完左边和右边的，就说明某个nums的元素已经找完了，跳出这个while
      }
      else if(nums[i] >= M_H_mz_min_match[mid]){
        left = mid + 1;
      }
      else if(nums[i] <= M_H_mz_max_match[mid]){
        right = mid - 1;
      }
    }
  }
  //对M-H库进行搜索


  for(int i = 0;i < num_len ; ++i){
    //遍历nums数组
    int left = 0;
    int right = M_2H_mz.size() - 1;//对M-2H库进行搜索
    while (left < right)
    {
        int mid = (left + right)/2;//中值
        if(nums[i] > M_2H_mz_min_match[mid] && nums[i] < M_2H_mz_max_match[mid]){
            auto it = mp.equal_range(mid);//找M-2H数据库中的下标是否与M-H搜索出来的有相同的，it为pair(两个元素都是迭代器)
            if (it.first == mp.end() & it.second == mp.end())
            {//如果这个物质只有M-2H，而没有M-H，则放入M_2H_res中
                M_2H_res.push_back({i , mid});
            }
            else{
                for (auto itr = it.first; itr != it.second; ++itr) {
                    vector<int> M_H_match = M_H_res[itr -> second];//itr的second属性装的是M_H_res中的行
                    M_H_M_2H_res.push_back({M_H_match[0] , M_H_match[1]  , i , mid});//将M-H搜索的结果和M-2H搜索的结果放一起
                    M_H_cut_index.insert(itr -> second);//将需要删除的行号插入到set中，因为说明了M-H的这个东西是具有M-2H的
                }
            }
            
            int left_mid = mid - 1;
            int right_mid = mid + 1;//向左和右寻找是否有符合条件的
            while(left_mid >= left && nums[i] >= M_H_mz_min_match[left_mid] && nums[i] <= M_H_mz_max_match[left_mid]){
                auto it = mp.equal_range(left_mid);//找M-2H数据库中的下标是否与M-H搜索出来的有相同的，it为pair(两个元素都是迭代器)
                if (it.first == mp.end() & it.second == mp.end())
                {//如果这个物质只有M-2H，而没有M-H，则放入M_2H_res中
                    M_2H_res.push_back({i , left_mid});
                }
                else{
                    for (auto itr = it.first; itr != it.second; ++itr) {
                        vector<int> M_H_match = M_H_res[itr -> second];//itr的second属性装的是M_H_res中的行
                        M_H_M_2H_res.push_back({M_H_match[0] , M_H_match[1]  , i , left_mid});//将M-H搜索的结果和M-2H搜索的结果放一起
                        M_H_cut_index.insert(itr -> second);//将需要删除的行号插入到set中，因为说明了M-H的这个东西是具有M-2H的
                    }
                }
            }
            //向mid的左边寻找符合条件的
            while(right_mid <= right && nums[i] >= M_H_mz_min_match[right_mid] && nums[i] <= M_H_mz_max_match[right_mid]){
            auto it = mp.equal_range(right_mid);//找M-2H数据库中的下标是否与M-H搜索出来的有相同的，it为pair(两个元素都是迭代器)
                if (it.first == mp.end() & it.second == mp.end())
                {//如果这个物质只有M-2H，而没有M-H，则放入M_2H_res中
                    M_2H_res.push_back({i , right_mid});
                }
                else{
                    for (auto itr = it.first; itr != it.second; ++itr) {
                        vector<int> M_H_match = M_H_res[itr -> second];//itr的second属性装的是M_H_res中的行
                        M_H_M_2H_res.push_back({M_H_match[0] , M_H_match[1]  , i , right_mid});//将M-H搜索的结果和M-2H搜索的结果放一起
                        M_H_cut_index.insert(itr -> second);//将需要删除的行号插入到set中，因为说明了M-H的这个东西是具有M-2H的
                    }
                }
            }
            //向mid的右边寻找符合条件的
            break;//找完左边和右边的，就说明某个nums的元素已经找完了，跳出这个while
        }
        else if(nums[i] >= M_2H_mz_min_match[mid]){
            left = mid + 1;
        }
        else if(nums[i] <= M_2H_mz_max_match[mid]){
            right = mid - 1;
        }
    }
  }
    //对M-2H库进行搜索
    vector<int> delete_index = vector(M_H_cut_index.begin() , M_H_cut_index.end());//set转化为vector
    sort(delete_index.begin() , delete_index.end());//进行排序

    for (signed i = delete_index.size() - 1; i >= 0; i--)
    {
       M_H_res.erase(M_H_res.begin() + delete_index[i]);
    }
    //删除已经标记的M_H_mz的对应下标


    vector<vector<vector<int>>> store = {M_H_res , M_2H_res , M_H_M_2H_res};

    return store;
}



int main(){
    vector<double> nums = {1,2,3,4,5,6,7};
    vector<double> M_H_mz = {1,2,3,4,5,6};
    vector<double> M_2H_mz = {7,8,9,10,11,12};
    int ppm = 100;
    auto result = matchMS1_separate(nums , M_H_mz , M_2H_mz , ppm);

    cin.get();
} 