// member function implementations go in this file

# include "MyString.h"
# include <iostream>
# include <cstring>

using namespace std;

// null constructor
// handles null initlizations of strings
MyString::MyString()
{
	nstring = new char[1];
	nstring[0] = '\0';
}

// parameter constructor
// handles assignments of strings usjing the stringName = ""
// input is a pointer to the first letter of the string
MyString::MyString(const char *input)
{
	nlength = static_cast<int>(strlen(input) + 1);
	nstring = new char[nlength];
	for (int i = 0; i < (nlength - 1); i++)
	{
		nstring[i] = input[i];
	}
	nstring[(nlength - 1)] = NULL;
}

// copy constructor
// handles setting one string equal to another
// S is the string to be set equal to the instance the function is called from
// called with MyString s1(S)
MyString::MyString(const MyString& S)
{
	cout << "in copy constructior" << endl;
	nlength = S.nlength;
	nstring = new char[nlength];
	for (int i = 0; i < (nlength - 1); i++)
	{
		nstring[i] = S.nstring[i];
	}

	if (nstring[nlength - 1] != '\0') { nstring[nlength - 1] = '\0'; }
}

// deconstructor
// deletes all the strings when the program closes
MyString::~MyString()
{
	cout << "In Deconstructor" << endl;
	delete[] nstring;
}

// gets the pointer to the first char of its instance of MyString
const char* MyString::c_str()  {
	return nstring;
}

// overloaded << operator
// returns the string using stringName.c_str()
// called with cout << stringName
ostream & operator<< (ostream& str, MyString& other)
{
	str << other.c_str();
	return str;
}

// overloaded == operator
// checks if s1 is equal to s2 
// returns true if they are equal and false if not
// called with s1 == s2
bool operator == (const MyString & S1, const MyString & S2)
{
	if (S1.nlength == S2.nlength)
	{
		short counter1 = S1.nlength;
		int counter2 = 0;
		int i = 0;
		while (i != counter1)
		{
			if (S1.nstring[i] != S2.nstring[i]) { counter2++; }
			i++;
		}
		
		if (counter2 != 0) { return false; }
		else { return true; }
	}
	else { return false; }

}

// overloaded assignment operator
// sets one string equal to another 
// called with s1 = s2
MyString& MyString::operator =(const MyString &S)
{
	nlength = S.nlength;
	delete[] nstring;
	nstring = new char[nlength];
	for (int i = 0; i < (nlength - 1); i++)
	{
		nstring[i] = S.nstring[i];
	}
	nstring[(nlength - 1)] = '\0';
	return *this;
}

// overloaded + operator
// concatinates two strings together
// called with s1 + s2
MyString operator + (const MyString& S1, const MyString & S2)
{
	int size = (S1.nlength - 1) + (S2.nlength - 1) + 1;
	char * temp = new char[size];
	for (int i = 0; i < (S1.nlength - 1); i++)
	{
		temp[i] = S1.nstring[i];
	}

	int j = 0;
	for (short k = S1.nlength - 1, j = 0; k < (size - 1); k++, j++)
	{
		temp[k] = S2.nstring[j];
	}

	if (temp[size - 1] != '\0') { temp[size - 1] = '\0'; }

	MyString S3(temp);
	delete[] temp;
	return S3;
}