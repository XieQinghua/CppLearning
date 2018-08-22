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

	static int test_count;
	virtual void show();
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
