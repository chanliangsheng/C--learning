#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort
#include <conio.h>
using namespace std;

vector<size_t> sort_indexes(vector<int> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings
  // when v contains elements of equal values 
  stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}

int main(){
  vector<int> a = {1,2,3,5,4,8};
  auto result = sort_indexes(a);
  for (auto itr = result.begin(); itr != result.end(); itr++)
  {
    cout << *itr << endl;
  }

  cin.get();
  
}