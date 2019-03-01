#include "MyString.h"
#include <iostream>
using namespace std;

// main goes in this file
int main() {

	cout << " ************** null constructor ************** " << endl;
	MyString s1;
	cout << "cout s1 : " << s1 << endl << endl;

	cout << " ************** param constructor ************** " << endl;
	s1 = "help";
	MyString s2 = " me!";
	cout << s1 << s2 << endl << endl;

	cout << " ************** copy constructor ************** " << endl;
	MyString s4 = "keyboard click";
	MyString s3(s4);
	cout << s4 << " = " << s3 << endl << endl;

	cout << " ************** c_str() function ************** " << endl;
	cout << "the first letter of s4 is : " << *s4.c_str() << endl << endl;

	cout << " ************** assignment operator ************** " << endl;
	MyString s5 = s1;
	cout << s5 << endl << endl;

	cout << " ************** == operator ************** " << endl;
	if (s1 == s2)
	{
		cout << s1 << " is equal to " << s2 << endl << endl;
	}
	else
	{
		cout << s1 << " is not equal to " << s2 << endl << endl;
	}
	
	if (s4 == s3)
	{
		cout << s4 << " is equal to " << s3 << endl << endl;
	}
	else
	{
		cout << s4 << " is not equal to " << s3 << endl << endl;
	}

	cout << " ************** + operator ************** " << endl;
	MyString s6 = s1 + s2;
	cout << s6 << endl << endl;

	return 0;
}
