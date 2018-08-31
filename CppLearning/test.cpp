#include"Util.h"
#include"test.h"

#define MAX(a,b) \
(a>b?a:b)

using namespace std;

void call_test() {
	test14();
}

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

	/*const int a = 1;
	int b = static_cast<int>(a);*/
}

void test12() {
	Base*base = static_cast<Base*>(new Derived);// 通过编译，且是安全的
	Derived*d = static_cast<Derived*>(new Base);// 通过编译，但是存在安全隐患
												//Another*a = static_cast<Base*>(new Base);// 没有任何关系的两个类，无法转换
	void *p = new Base;

}

void test13() {
	/*int temp;
	cin >> temp;*/
	cout << "请输入一个数：" << endl;
	int input;
	cin >> input;
	const int a = input;
	const int*pointer_const = &a;
	int*b = const_cast<int*>(pointer_const);
	*b = 20;
	//int a = 10;
	//int *b = &a;
	//*b = 20;
	cout << "b = " << *b << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "&a = " << &a << endl;
	//a = 50;
	cin.get();
}

void test14() {
	/*Derived d;
	cout << "reinterpret_cast<Base*>(&d) = " << reinterpret_cast<Base*>(&d) << endl;
	cout << "static_cast<Base*>(&d) = " << static_cast<Base*>(&d) << endl;*/
	char s[] = "hello world!";
	long l = reinterpret_cast<long>(s);
	cout << "l = " << l << endl;
}

void test15() {
	union Data {
		struct {
			int x;
			int y;
		} s;
		int x;
		int y;
	}d;
	d.x = 1;
	d.y = 2;
	cout << d.x << endl << d.y << endl;
	d.s.x = d.x*d.x;
	d.s.y = d.y + d.y;
	cout << d.s.x << endl << d.s.y << endl;
	cout << d.x << endl << d.y << endl;
	cout << "sizeof = " << sizeof(d) << endl;
}

void test16() {
	const char*st = "How are you!!!!!";
	char a[11];
	strcpy(a, st);
	cout << a << endl;
}