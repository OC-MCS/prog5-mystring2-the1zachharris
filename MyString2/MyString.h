#pragma once
#include <iostream>
using namespace std;


// MyString class declaration goes here

class MyString
{
private:
	char* nstring;
	int nlength;

public:
	MyString(void);// default sets string to NULL
	MyString(const char* input);// Takes in a string and creates an object
	MyString(const MyString & S);// Copy constructor
	~MyString(void);// destructor deletes the nstring at the end
	const char* c_str();// gets pointer to string


	MyString& operator = (const MyString& S);// if A and B are object B is "neil", the A =B therefore A is "neil"
	friend  bool operator ==(const MyString& S1, const MyString & S2);// checks if both strings are equal
	friend MyString operator + (const MyString& S1, const MyString & S2);// concatinates strings
};

ostream& operator<< (ostream& str, MyString& other);// used to cout strings