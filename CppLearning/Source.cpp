/*
**@Author:Jason.Lee
**@Date:2018-8-19
*/

#include<iostream>
#include"Util.h"

#define MAX(a,b) \
(a>b?a:b)
using namespace std;

void change(const int*pt, int n) {
	int *pc = const_cast<int*>(pt);
	*pc += n;
}

void test1() {
	int a = 100;
	const int b = 1000;
	cout << "a = " << a << " b = " << b << endl;
	change(&b, a);
	cout << "a = " << a << " b = " << b << endl;
}

void test2() {
	int b = 1;
	const int *a = &b;
	cout << *a << endl;
	//*a++;
	//cout << *a << endl;
	int*c = const_cast<int*>(a);
	*c = 2;
	cout << *c << endl;
}

void test3() {

	Util *u = new Tool();
	Tool *t = dynamic_cast<Tool*>(u);
	if (t != nullptr) {
		t->get_count();
	}
	else {
		cout << "failure!" << endl;
	}
	if (typeid(Util) == typeid(*u)) {
		cout << "typeid(Util) == typeid(u)" << endl;
	}
	else {
		cout << "typeid(Util) != typeid(u)" << endl;
	}

	if (typeid(Tool) == typeid(*u)) {
		cout << "typeid(Tool) == typeid(u)" << endl;
	}
	else {
		cout << "typeid(Tool) != typeid(u)" << endl;
	}
	cout << typeid(*u).name() << endl;
}


void test4() {
	int a = 10;
	int *i = &a;
	long pc = reinterpret_cast<long>(i);
	char *cr = reinterpret_cast<char*>(i);
	long *l = reinterpret_cast<long*>(i);
	
	cout << *i << endl;
	cout << hex << pc << endl;
	cout << cr << endl;
	cout << l << endl;
}

void test5() {
	int a = 1;
	int b = 3;
	cout << MAX(a, b) << endl;
}

void test6() {
	Util u;
	u.test_inline();
}
int main() {
	/*Util u(1, "Hello");
	Tool t;
	t.show();*/
	{
		//Tool t;
		//Util u;
		//Util *uuu = new Tool();
		//delete uuu;
	}
	//test2();
	/*
	Util u;
	u.get_count();
	cout<<Util::test_count;*/
	test6();
	cin.get();
	return 0;
}