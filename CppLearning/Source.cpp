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
	const int b = 1;
	const int *a = &b;
	cout << *a << endl;
	//*a++;
	//cout << *a << endl;
	int*c = const_cast<int*>(a);
	*c = 2;
	cout << *c << endl;
	cout << b << endl;
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

void test7() {
	float ff = 3.1415f;
	int i = (int)ff;
	cout << ff << endl;
	int a = static_cast<int>(ff);
	cout << a << endl;
}

void test8() {

	Util u;
	const Util u_const;
	u.test_const_function();
	u.test_const_function(100);
	u_const.test_const_function();
}

#define pi_define 3.1415f

const double pi_const = 3.1415926f;

void test9() {
	double pi = pi_const;
	cout << "double pi = " << pi << endl;
	pi = pi_define;
	cout << "double pi = " << pi << endl;

}

void test10() {
	const int a = 10;
	const int b = 20;
	const int *p = &a;
	cout << *p << endl;
	p = &b;
	cout << *p << endl;
	int c = 30;
	int* const ppp = &c;
	c = 40;
	cout << *ppp << endl;
}

void test11() {
	Base*base = new Derived;
	if (Derived* derived = dynamic_cast<Derived*>(base)) {
		cout << "基类指针转换派生类指针成功" << endl;
		derived->show();
	}
	else {
		cout << "基类指针转换派生类指针失败" << endl;
		//derived->show();
	}
	base = new Base;
	if (Derived* derived = dynamic_cast<Derived*>(base)) {
		cout << "基类指针转换派生类指针成功" << endl;
		derived->show();
	}
	else {
		cout << "基类指针转换派生类指针失败" << endl;
		derived->show();
	}

	int testttt = 1;
	float ffff = static_cast<float>(testttt);
	Base*b = new Derived;
	Derived *d = static_cast<Derived*>(new Base);

	/*char *a = "Hello";
	int a = static_cast<int>("");*/
}

void test12() {
	Base*base = static_cast<Base*>(new Derived);// 通过编译，且是安全的
	Derived*d = static_cast<Derived*>(new Base);// 通过编译，但是存在安全隐患
	Another*a = static_cast<Base*>(new Base);// 没有任何关系的两个类，无法转换
}
int main() {
	
	cin.get();
	return 0;
}