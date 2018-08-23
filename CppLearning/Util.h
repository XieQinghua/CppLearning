/*
**@Author:Jason.Lee
**@Date:2018-8-19
*/
#pragma once

#include<iostream>
#include<string>

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