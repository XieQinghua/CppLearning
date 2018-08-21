/*
**@Author:Jason.Lee
**@Date:2018-8-19
*/

#include<iostream>
#include"Util.h"
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
	test2();
	
	cin.get();
	return 0;
}