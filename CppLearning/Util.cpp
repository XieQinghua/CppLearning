/*
**@Author:Jason.Lee
**@Date:2018-8-19
*/

#include"Util.h"

int Util::count = 0;
int Util::test_count = 0;

Util::Util() {
	cout << "Util constructor function:Util()" << endl;
	name = "no name";
}

Util::Util(const Util & u)
{
	cout << "Util::Util(const Util & u);" << endl;
}

Util::~Util() {
	cout << "Util deconstructor function:~Util(),object name is " << name << "." << endl;
}

Util::Util(int id, string name) :id(id), name(name) {
	cout << "Util constructor function:Util(int ,string)" << endl;
	cout << "parameter:id = " << id << endl;
	cout << "parameter:name = " << name << endl;
}

inline void Util::test_inline2() {
	cout << "I am a inline function in Util,define function body outside!" << endl;
}
Tool::Tool() {
	cout << "Tool constructor function:Tool()" << endl;
}

Tool::~Tool() {
	cout << "Tool deconstructor function:~Tool()" << endl;
}
void Util::show() {
	cout << "id = " << id << endl << "name = " << name << endl;
}

void Util::test_const_function()
{
	cout << "void Util::test_const_function()" << endl;
}

void Util::test_const_function() const
{
	cout << "void Util::test_const_function() const" << endl;	
}

void Util::test_const_function(int test)
{
	cout << "void Util::test_const_function(int test=" << test << ")" << endl;
}

void Util::test_show_const()
{
	cout << "function:void Util::test_show_const()" << endl;
}

void Util::test_show_const() const
{
	cout << "function:void Util::test_show_const() const" << endl;
}

Util & Util::operator=(const Util & src)
{
	if (this != &src) {
		cout << "calling operator=(const Util&)" << endl;
	}
	return *this;
}

void Tool::show() {
	cout << "function = " << function << endl << "typeclass = " << typeclass << endl;
}

void TestA::show() const
{
	cout << "a = " << a << "b = " << b << endl;
}

int TestC::c = 1;

int TestC::show()
{
	cout << "c = " << TestC::c << endl;
	return 0;
}
