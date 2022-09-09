/* Write your test code for the ULListStr in this file */
#include <cstddef> 
#include <iostream>
#include <stdexcept>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
	ULListStr dat;
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");
	cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
	// prints: 8 7 9
	cout << dat.front() << " " << dat.back() << endl;
	//prints 8 9 ,, (front() back() does not change anything only retrieves value)
	cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
	dat.pop_back();
	dat.pop_front();
	dat.push_back("5");
	cout << dat.get(0) << " " << dat.get(1) << " " << endl;
	//prints 7 5
	dat.set(1, "8"); // setting 8 as the new value at index 1
	cout << dat.get(0) << " " << dat.get(1) << " " << endl;
	//prints 7,8
	dat.clear(); 
	cout << dat.size() << endl; // size should be 0, cleared
	cout << boolalpha << dat.empty() << endl;
	//print true 
	dat.push_back("5");
	dat.push_front("3");
	dat.push_back("1");
	dat.push_front("6");
	dat.push_back("9");
	cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << " " << dat.get(4) << " " << endl;
	//prints 6 3 5 1 9
	cout << dat.size() << endl; // print 5
	dat.pop_back();
	dat.pop_front();
	cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << endl;
	//prints 3 5 1
	cout << boolalpha << dat.empty() << endl;
	//print false
	dat.clear();
	dat.push_back("I");
	dat.push_front("LOVE");
	dat.push_back("YOU");
	dat.push_front("SO");
	dat.push_back("MUCH");
	dat.push_front("YOU");
	dat.set(0, "I");
	dat.set(3, "YOU");
	dat.set(1, "LOVE");
	dat.pop_back();
	dat.pop_back();
	dat.set(2, "YOU");
	cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
	//print "I LOVE YOU"

  return 0;
}
