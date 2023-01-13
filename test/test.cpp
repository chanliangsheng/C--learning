#include <iostream>
#include <utility>
using namespace std;

void swap(int a , int b){
	cout << "a address is" << &a << endl;
	cout << "b address is" << &b << endl;
	int temp = b;
	b = a;
	a = temp;

	cout << "a address is" << &a << endl;
	cout << "b address is" << &b << endl;
}
int main()
{
       //initialize the random generator 
     	//Create a 10 x 1 random vector and printing it

	cout << sizeof(pair<double , double>) << endl;

	system("pause");
  	return 0;
}