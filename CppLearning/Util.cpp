/*
**@Author:Jason.Lee
**@Date:2018-8-19
*/

#include"Util.h"

Util::Util() {
	cout << "Util constructor function:Util()" << endl;

}

Util::~Util() {
	cout << "Util deconstructor function:~Util()" << endl;
}

Util::Util(int id, string name) :id(id), name(name) {
	cout << "Util constructor function:Util(int ,string)" << endl;
	cout << "parameter:id = " << id << endl;
	cout << "parameter:name = " << name << endl;
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

void Tool::show() {
	cout << "function = " << function << endl << "typeclass = " << typeclass << endl;
}