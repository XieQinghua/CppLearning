/*
**@Author:Jason.Lee
**@Date:2018-8-19
*/
#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<array>
#include<deque>

using namespace std;

class Util {
private:
	static int count;
	int id;
	string name;

public:
	Util();
	Util(int id, string name);
	~Util();
	inline void test_inline() {
		cout << "I am a inline function in class Util" << endl;
	}
	inline void test_inline2();
	static int test_count;
	virtual void show();
	void test_const_function();
	void test_const_function() const;
	void test_const_function(int test);
	static void get_count() {
		cout << count << endl;
	}
};

class Tool :public Util {
private:
	int function;
	string typeclass;
public:
	Tool();
	~Tool();
	virtual void show();
};

class AnotherUtil {

};

class Another {
	int a;
};

class Base {
private:
	int b;
public:
	virtual void show() {
		cout << "void Base::show();" << endl;
	};
	virtual ~Base() {};
};

class Derived :public Base{
private:
	int d;
public:
	void show() {
		cout << "void Derived::show();" << endl;
	};
};

// 包含两个int成员和一个成员函数的测试类
class TestA {
private:
	int a;
	int b;
public:
	void show() const;
};

// 只包含两个int成员的情况
class TestB {
private:
	int a;
	int b;
};

// 包含两个成员和一个静态成员的情况
class TestC {
private:
	int a;
	int b;
	static int c;
public:
	static int show();
};

class TestD :public TestA {
private:
	int x;
	int y;
};

//可能会引起字节对齐的E类
class TestE  {
private:
	float f1;
	float f2;
	char c;
};

// 两层继承结构体系
class TestF :public TestD {

};

// 多继承
class TestG :public TestD, TestE {

};