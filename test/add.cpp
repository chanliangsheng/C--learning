#include <iostream>
#include <cstring>
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

int main(void)
{
    using namespace std;
    int sum_store = 0;
    int money;    
    while (1)
    {
      cout << "please input your money:";
      cin >> money;
      if (cin.fail())
      {
        cout << "your inpur is failed , input again:";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      sum_store = money + sum_store;
      cout << "you have " << sum_store << "$"<< endl;
    }
    
    

    while (1)
    {
      int ch = 7;
      cin >> ch;
      if (cin.fail())
      {
        cout << "your inpur is failed , input again:";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      

    }
    
    
     _getch();
    return 0;
}