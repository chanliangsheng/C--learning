// A simple C++ program to find N maximum
// combinations from two arrays,
#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <queue>
#include <set>
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
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}
 
// Function prints k maximum possible combinations
auto KMaxCombinations(vector<int>& A,
                      vector<int>& B, int K)
{
    // sort both arrays A and B
    vector<int> A_order = sort_indexes(A);
    vector<int> B_order = sort_indexes(B);
    // 进行A和B的排序，返回下标
    sort(A.begin() , A.end());
    sort(B.begin() , B.end());
    // A和B进行排序
 
    int A_len = A.size();
    int B_len = B.size();
    // A和B的长度

    std::vector<vector<int>> result;
    // 存储最终的结果
    
    priority_queue<pair<int, pair<int, int> > > pq;
    // 创建最大堆
    
    set<pair<int, int> > my_set;
    // 用于去重
    
    pq.push(make_pair(A[A_len - 1] + B[B_len - 1],
                      make_pair(A_len - 1 , B_len - 1)));
    // 将两个数组的最大值放入最大堆

    my_set.insert(make_pair(A_len - 1 , B_len - 1));
 
    // iterate upto K
    for (int count = 0; count < K; count++)
    {
        // tuple format (sum, (i, j)).
        pair<int, pair<int, int> > temp = pq.top();
        pq.pop();
        // 弹出最大值
        int i = temp.second.first;
        int j = temp.second.second;
        result.push_back({A_order[i] , B_order[j]});
        // 将对应的索引保存到最终结果
        
        if ((i - 1) >= 0)
        {
            int sum = A[i - 1] + B[j];
 
        // insert (A[i - 1] + B[j], (i - 1, j))
        // into max heap.
            pair<int, int> temp1 = make_pair(i - 1, j);
 
        // insert only if the pair (i - 1, j) is
        // not already present inside the map i.e.
        // no repeating pair should be present inside
        // the heap.
            if (my_set.find(temp1) == my_set.end())
            {
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
 
        }
        
        if ((j - 1) >= 0)
        {
            // insert (A[i] + B[j - 1], (i, j - 1))
            // into max heap.
            int sum = A[i] + B[j - 1];
            auto temp1 = make_pair(i, j - 1);
    
            // insert only if the pair (i, j - 1)
            // is not present inside the heap.
            if (my_set.find(temp1) == my_set.end())
            {
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
        }
        
        
        
    }
    return(result);
}
 
// Driver Code.
int main()
{
    vector<int> A = { 1,2,3,4};
    vector<int> B = { 8,9,10,11 };
    int K = 4;
    // Function call
    auto result = KMaxCombinations(A, B, K);
    _getch();
    return 0;
}